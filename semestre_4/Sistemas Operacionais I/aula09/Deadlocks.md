## 1. Introdução

- Dispositivos e recursos são compartilhados o tempo todo: impressora, disco, arquivos, etc.
- **Deadlock**: processos ficam **parados**, sem possibilidade de continuar seu processamento.
- Analogia clássica: **cruzamento de trânsito** — carros vindos de 4 direções bloqueiam uns aos outros, nenhum consegue avançar (situação de impasse/deadlock).

## 2. Tipos de Recursos

- **Preemptivos**: podem ser retirados do processo **sem prejuízo**.
    - Ex.: Memória, CPU.
- **Não-preemptivos**: **não podem** ser retirados do processo, pois causariam prejuízo.
    - Ex.: CD-ROM, unidades de fita.
    - **Deadlocks ocorrem com esse tipo de recurso.**

## 3. Ciclo de Vida da Requisição de Recursos

1. **Requisição** do recurso;
2. **Utilização** do recurso;
3. **Liberação** do recurso.

Se o recurso requisitado **não está disponível**, duas situações podem ocorrer:

- O processo fica **bloqueado** até o recurso ser liberado; ou
- O processo **falha** e, após um tempo, tenta requisitar novamente.

## 4. As Quatro Condições para Deadlock

Todas devem ocorrer simultaneamente para que exista deadlock:

1. **Exclusão Mútua**: um recurso só pode estar alocado a **um processo** por vez;
2. **Uso e Espera** (_hold and wait_): processos que já possuem algum recurso podem **requisitar outros recursos**;
3. **Não-preempção**: recursos já alocados **não podem ser retirados** à força — só o próprio processo pode liberá-los;
4. **Espera Circular**: um processo pode esperar por recursos alocados a outro processo, formando um **ciclo**.

### Exemplo de Espera Circular

> Processo "A" espera por "B", que espera por "C", que espera por "A".

## 5. Grafos de Alocação de Recursos

- Deadlocks costumam ser representados por **grafos**, facilitando **detecção, prevenção e recuperação**.
- A ocorrência de **ciclos** no grafo pode indicar um deadlock.

**Notação:**

- Círculo = Processo; Quadrado = Recurso.
- Seta de Recurso → Processo: recurso **alocado** ao processo.
- Seta de Processo → Recurso: processo **requisita** o recurso.

**Exemplos:**

- (a) Recurso R alocado ao Processo A;
- (b) Processo B requisita Recurso S;
- (c) **Deadlock**: ciclo entre processos T, D, C, U (T→U→D→C→T, formando espera circular).

## 6. Estratégias para Tratar Deadlock

Quatro abordagens principais:

1. **Ignorar** o problema;
2. **Detectar e recuperar** o problema;
3. **Evitar dinamicamente** o problema — alocação cuidadosa de recursos;
4. **Prevenir** o problema, evitando que uma das quatro condições necessárias ocorra.

---

## 7. Estratégia 1: Ignorar o Problema

- Compara-se a **frequência** de ocorrência de deadlocks com a frequência de **outras falhas** do sistema (hardware, compilador, S.O., etc.).
- Se o esforço para solucionar for **muito maior** do que o benefício (dado que deadlocks são raros), pode-se simplesmente **ignorar**.
- Conhecido como **Algoritmo do Avestruz** (_Ostrich Algorithm_) — "enfiar a cabeça na areia".
	-  Resenha da professora
- Considerações: frequência do problema vs. alto custo de estabelecer condições rígidas para uso de recursos.

---

## 8. Estratégia 2: Detectar e Recuperar

### Conceito

- Permite que deadlocks **ocorram**; o sistema tenta **detectar as causas** e **solucionar** a situação depois.

### Algoritmos de Detecção

- Detecção com **um recurso de cada tipo**;
- Detecção com **vários recursos de cada tipo**;

### Algoritmos de Recuperação

- Recuperação por **preempção**;
- Recuperação por **rollback** (retorno a um estado anterior);
- Recuperação por **eliminação de processos**.

### 8.1 Detecção com Um Recurso de Cada Tipo

- Constrói-se um **grafo** de alocação de recursos;
- Se houver **ciclos** → existe(m) potencial(is) deadlock(s).

### 8.2 Detecção com Vários Recursos de Cada Tipo

Estruturas de dados usadas:

- **Vetor de recursos existentes (E)**: quantidade total de cada classe de recurso.
    - Ex.: `E1 = 2` unidades de fita → existem 2 instâncias daquele tipo.
- **Vetor de recursos disponíveis (A)**: quanto de cada recurso está livre no momento.
- **Matriz de Alocação Corrente (C)**: `C[i][j]` = número de instâncias do recurso `j` alocadas ao processo `i`.
- **Matriz de Requisições (R)**: `R[i][j]` = número de instâncias do recurso `j` que o processo `i` ainda precisa.

#### Exemplo prático (Fitas, Plotters, Impressoras, CD-ROM)

Cenário: **3 processos** (P1, P2, P3) e **4 tipos de recursos**: Unidades de Fita (UF), Plotters (P), Impressoras (I), Unidade de CD-ROM (UCD).

**Recursos existentes (E):**

|UF|P|I|UCD|
|:-:|:-:|:-:|:-:|
|4|2|3|1|

**Recursos disponíveis no início (A):**

|UF|P|I|UCD|
|:-:|:-:|:-:|:-:|
|2|1|0|0|

**Matriz de Alocação (C)** — o que cada processo já possui:

|Processo|UF|P|I|UCD|
|:-:|:-:|:-:|:-:|:-:|
|P1|0|0|1|0|
|P2|2|0|0|1|
|P3|0|1|2|0|

**Matriz de Requisições (R)** — o que cada processo ainda precisa:

|Processo|UF|P|I|UCD|
|:-:|:-:|:-:|:-:|:-:|
|P1|2|0|0|1|
|P2|1|0|1|0|
|P3|2|1|0|0|

> Contexto: P1 usa 1 impressora e precisa de mais 2 fitas + 1 CD-ROM; P2 usa 2 fitas + 1 CD-ROM e precisa de mais 1 fita + 1 impressora; P3 usa 1 plotter + 2 impressoras e precisa de mais 2 fitas + 1 plotter.

**Passo a passo do algoritmo:**

1. Calcula-se `A` (recursos disponíveis) = `E` menos o que está alocado (soma das colunas de `C`);
2. Procura-se um processo cuja linha de requisição `R[i]` seja **menor ou igual** a `A` (ou seja, o processo pode ter todas as suas requisições atendidas com o que está disponível agora);
3. Se encontrado, **assume-se que esse processo roda até terminar e libera todos os seus recursos** — soma-se sua linha de `C` a `A`, e zera-se sua linha em `C` e `R`;
4. Repete-se o processo com os processos restantes;
5. **Se todos os processos puderem "rodar" e terminar dessa forma → não há deadlock**;
6. **Se sobrar algum processo cuja requisição nunca pode ser satisfeita → esses processos estão em deadlock**.

**Execução do algoritmo passo a passo:**

|Passo|A disponível|Comparação|Processo liberado|Novo A|
|:-:|:--|:--|:-:|:--|
|1|(2,1,0,0)|R(P3)=(2,1,0,0) ≤ A ✓|**P3** roda e libera (0,1,2,0)|(2,2,2,0)|
|2|(2,2,2,0)|R(P2)=(1,0,1,0) ≤ A ✓|**P2** roda e libera (2,0,0,1)|(4,2,2,1)|
|3|(4,2,2,1)|R(P1)=(2,0,0,1) ≤ A ✓|**P1** roda e libera (0,0,1,0)|(4,2,3,1)|

Ao final: `A = E = (4,2,3,1)` e as matrizes `C` e `R` ficam totalmente **zeradas** → **todos os processos conseguiram terminar → não há deadlock** 

> Se em algum passo **nenhum processo** restante tivesse `R[i] ≤ A`, os processos restantes estariam em **deadlock**.

#### Cuidados na Detecção

- O sistema geralmente busca por deadlocks **periodicamente**;
- **Cuidado**: evitar ociosidade da CPU — se muitos processos estão em deadlock, poucos processos restam em execução, então não adianta rodar a verificação com frequência excessiva.

### 8.3 Recuperação de Deadlock

- **Por Preempção**: retirar **temporariamente** um recurso de seu dono atual (processo).
- **Por Rollback**: os recursos alocados a um processo são periodicamente salvos em **arquivos de verificação (checkpoints)**; ao detectar deadlock, o(s) processo(s) volta(m) ao estado anterior ao deadlock.
    - **Solução cara** (overhead de checkpoint).
- **Por Eliminação de Processos**: processos que fazem parte do ciclo de deadlock são **retirados/mortos**.
    - Melhor solução para processos que **não causam efeito negativo** ao serem reiniciados.
        - Ex. 1: **compilação** → sem problemas se reiniciada;
        - Ex. 2: **atualização de banco de dados** → pode causar problemas (inconsistência) se interrompida e reiniciada.

---

## 9. Estratégia 3: Evitar Dinamicamente o Problema

- Alocação **individual** de recursos, conforme o processo necessita;
- Soluções também utilizam **matrizes** (semelhante à detecção);
- Requer **escalonamento cuidadoso** — alto custo, pois exige **conhecimento prévio** de quais recursos cada processo usará.

### Algoritmos

- **Algoritmo do Banqueiro** para **um único** tipo de recurso;
- **Algoritmo do Banqueiro** para **vários** tipos de recursos.

### Estado Seguro vs. Estado Inseguro

- **Estado Seguro**: não provoca deadlocks; existe uma forma de atender **todas** as requisições pendentes, terminando **normalmente todos os processos**.
    - A partir de um estado seguro, há **garantia** de que os processos vão terminar.
- **Estado Inseguro**: **pode** provocar deadlocks (mas não necessariamente provoca).
    - A partir de um estado inseguro, **não há garantia** de que os processos terminarão corretamente.

### 9.1 Algoritmo do Banqueiro

- Idealizado por **Dijkstra (1965)**.
- Analogia: um **banqueiro (S.O.)** decide conceder ou não **crédito (recursos)** a seus **clientes (processos)**.
    - Nem todo cliente precisa de **toda** a linha de crédito disponível de uma vez.
- **Funcionamento**: a cada requisição (no momento em que ela ocorre), verifica-se se atendê-la leva a um **estado seguro**.
    - Se **sim** → a requisição é atendida imediatamente;
    - Se **não** → o atendimento é **adiado** para outro momento.

#### Exemplo (um único tipo de recurso)

- Cada cliente tem um valor **possuído** e um **máximo de linha de crédito**;
- O banco tem um total de recursos **livres**;
- Estado é **Seguro** se, mesmo no pior caso (todos pedindo o máximo), o banqueiro consegue satisfazer **pelo menos um** cliente por vez, liberando recursos para os demais em sequência;
- Estado é **Inseguro** se existe a possibilidade de que, em algum momento, **nenhum cliente possa ser plenamente atendido** (mesmo que nada de ruim tenha ocorrido ainda).

> Exemplo do slide: com "Livre = 2" o estado ainda é **Seguro** (dá para atender C, que libera recursos para B ou D); mas ao reduzir para "Livre = 1", o estado se torna **Inseguro**.

#### Algoritmo do Banqueiro para Vários Tipos de Recursos

- Mesma ideia do caso de um único recurso, mas usando **duas matrizes** (alocação e máximo necessário/requisição), análogas às matrizes `C` e `R` da detecção.

#### Vantagens e Desvantagens

**Desvantagens:**

- **Pouco utilizado na prática**, pois é difícil saber **antecipadamente** quais recursos cada processo vai precisar;
- Escalonamento cuidadoso é **caro** para o sistema;
- O **número de processos é dinâmico** e pode variar constantemente, tornando o algoritmo **custoso**.

**Vantagem:**

- Na **teoria**, o algoritmo é **ótimo**.

---

## 10. Estratégia 4: Prevenir Deadlocks

- Consiste em **atacar** uma das **quatro condições necessárias** para deadlock, impedindo que ela ocorra:
    1. Negar exclusão mútua (nem sempre possível — alguns recursos são inerentemente exclusivos);
    2. Negar uso e espera (exigir que o processo solicite **todos** os recursos de uma vez, no início);
    3. Permitir preempção (forçar liberação de recursos, quando possível);
    4. Negar espera circular (impor uma **ordenação** total dos recursos, exigindo que os processos os solicitem em ordem crescente, por exemplo).

## 11. Observação Final

- Deadlocks **podem ocorrer sem envolvimento direto de recursos físicos** — por exemplo, se **semáforos forem implementados incorretamente** (erros de lógica na ordem de `down`/`up`), pode-se gerar um deadlock lógico entre processos, mesmo sem disputa por dispositivos de hardware.
