
## Tipos de hazard (conflito)

|Tipo|Sigla|Descrição|
|---|---|---|
|Dependência verdadeira|RAW (_Read After Write_)|Uma instrução lê um operando que ainda está sendo produzido por uma instrução anterior|
|Antidependência|WAR (_Write After Read_)|Uma instrução escreve em um operando que ainda será lido por uma instrução anterior|
|Dependência de saída|WAW (_Write After Write_)|Duas instruções escrevem no mesmo operando|

> **WAR e WAW** não são problema em pipelines com ordem de execução mantida. Tornam-se problema em processadores superescalares — solução usual: **renomeação de registradores**.

---

## Problema

Algumas dependências (RAW) fazem com que o pipeline precise esperar pelo resultado de uma instrução anterior ainda não concluída, quebrando o ideal de uma instrução finalizada por ciclo de clock.

---

## Soluções para RAW

### 1. NOP / Escalonamento pelo compilador

O compilador insere instruções `nop` ou reordena as instruções para criar ciclos de distância entre a produção e o uso do dado.

### 2. Parada do pipeline (stall / bubble)

- O hardware detecta o hazard e **congela** os estágios IF e ID (impede que PC e IF/ID sejam alterados).
- Uma **bolha** (`nop`) é inserida no estágio EX — os sinais de controle de EX, MEM e WB são desativados.
- O pipeline aguarda até que o dado esteja disponível.

### 3. Adiantamento de dados (forwarding / bypassing)

- Caminho interno que leva o resultado já calculado diretamente à entrada da ULA, **sem esperar o Write Back**.
- Utiliza buffers de pipeline intermediários (EX/MEM, MEM/WB) em vez dos registradores visíveis ao programador.

> Em alguns casos — como `lw` seguido imediatamente de instrução dependente — **nem o forwarding resolve** e um stall de 1 ciclo é obrigatório.

---

## Unidade de Forwarding

### Sinais de controle dos MUX

|Sinal|Fonte|Significado|
|---|---|---|
|`ForwardA/B = 00`|ID/EX|Operando vem do banco de registradores (sem hazard)|
|`ForwardA/B = 10`|EX/MEM|Forwarding do resultado da ULA do ciclo anterior|
|`ForwardA/B = 01`|MEM/WB|Forwarding da memória de dados ou de ULA mais antiga|

### Condições de detecção

**Dependência EX** (ForwardA/B = 10):

```
EX/MEM.RegWrite
AND (EX/MEM.Rd ≠ 0)
AND (EX/MEM.Rd = ID/EX.Rs1)  → ForwardA = 10

EX/MEM.RegWrite
AND (EX/MEM.Rd ≠ 0)
AND (EX/MEM.Rd = ID/EX.Rs2)  → ForwardB = 10
```

**Dependência MEM** (ForwardA/B = 01):

```
MEM/WB.RegWrite
AND (MEM/WB.Rd ≠ 0)
AND (MEM/WB.Rd = ID/EX.Rs1)  → ForwardA = 01

MEM/WB.RegWrite
AND (MEM/WB.Rd ≠ 0)
AND (MEM/WB.Rd = ID/EX.Rs2)  → ForwardB = 01
```

### Caso especial — acumulação no mesmo registrador

Quando se escreve e lê repetidamente no mesmo registrador (ex: somar elementos de um vetor), EX e MEM podem querer forwardar para a mesma instrução ao mesmo tempo. **EX tem prioridade**; a lógica MEM inclui uma condição extra:

```
MEM/WB.RegWrite
AND (MEM/WB.Rd ≠ 0)
AND (EX/MEM.Rd ≠ ID/EX.Rs1)   ← condição extra
AND (MEM/WB.Rd = ID/EX.Rs1)   → ForwardA = 01

MEM/WB.RegWrite
AND (MEM/WB.Rd ≠ 0)
AND (EX/MEM.Rd ≠ ID/EX.Rs2)   ← condição extra
AND (MEM/WB.Rd = ID/EX.Rs2)   → ForwardB = 01
```

---

## Unidade de Detecção de Hazard (Hazard Detection Unit)

Detecta o caso **load-use**: instrução `lw` seguida imediatamente de instrução que usa o dado carregado. Forwarding não resolve porque o dado só sai da memória no final do estágio MEM.

### Condição de detecção

```
ID/EX.MemRead
AND ( (ID/EX.Rd = IF/ID.Rs1) OR (ID/EX.Rd = IF/ID.Rs2) )
→ stall the pipeline
```

### Ação ao detectar stall

1. Congela o PC e o registrador de pipeline IF/ID (preserva instrução atual e a seguinte).
2. Desativa todos os sinais de controle de EX, MEM e WB → insere bolha (`nop`) no pipeline.

---

## Observação

> NOP, stall e forwarding são soluções específicas para **data hazards (RAW)**. Os outros tipos de conflito de pipeline são tratados por mecanismos distintos (conflitos estruturais → caches separadas, múltiplas portas; conflitos de controle → branch prediction, delayed branch).