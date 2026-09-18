## 1. Introdução

Processos precisam se comunicar e competem por recursos. Três aspectos importantes:

- Como um processo **passa informação** para outro;
- Como garantir que processos **não invadam** espaços uns dos outros;
- **Dependência entre processos**: sequência adequada de execução.

> Comunicação entre processos é mais eficiente se **estruturada** e não depender de interrupções.

### O que são interrupções?

- Evento **externo** que faz o processador parar a execução corrente e desviar para uma **rotina de interrupção** (geralmente por E/S).
- Ao terminar o tratamento, o controle **retorna exatamente ao estado anterior**.

## 2. Condição de Corrida (Race Condition)

### Exemplos motivadores

- Threads A e B, x=0, y=0 inicialmente.
    - **Thread A**: `x=1`; **Thread B**: `y=2` → x será **obrigatoriamente 1** (não há interferência, variáveis independentes).
    - **Thread A**: `x=y+1`; **Thread B**: `y=2; y=y*2` → resultado de x pode ser **1, 3 ou 5** — **não-determinismo**!

> **Race Condition**: situação em que duas ou mais threads/processos correm uma contra a outra para acessar/alterar dado compartilhado, e o resultado depende de qual delas "chega primeiro".

### Definição formal

**Condição de Corrida**: situações onde dois ou mais processos leem/escrevem dado compartilhado e o **resultado depende da ordem/momento** de execução.

- **Difícil de depurar**: não se pode prever quando um processo será suspenso.

### Exemplo clássico: Print Spooler

- Processo deseja imprimir → coloca nome do arquivo em uma **spooler directory**;
- **Printer daemon** verifica periodicamente a lista e imprime os arquivos.
- **Problema**: se dois processos leem a mesma variável `slot` (próximo slot livre) **antes** de um deles atualizar, ambos escrevem no **mesmo slot**, e um dos arquivos se perde:

```
Processo A:                      Processo B:
get_prox_slot(slot);             get_prox_slot(sl);
set_nomearq(slot, nomearq);      set_nomearq(sl, nomearq);
slot++;                          slot++;
set_prox_slot(slot);             set_prox_slot(slot);
```

Ambos leem `slot=5` antes de incrementar → **condição de corrida** (arquivo de um processo sobrescreve o do outro).

### Exemplo: Venda de passagens de avião

- OP1 (Brasil) lê Cadeira1 vaga; OP2 (Japão) lê Cadeira1 vaga; OP1 compra; OP2 compra → **ambos compram a mesma cadeira**!
- **Solução simples**: apenas um operador vende por vez → gera **fila** → **ineficiência**.

## 3. Região Crítica (R.C.)

### Definição

- **Região/Seção Crítica**: trecho de código onde se acessa (leitura/escrita) um **recurso compartilhado** por dois ou mais processos.
- É necessário garantir que **dois ou mais processos não estejam simultaneamente** na R.C.
- Essa restrição é chamada de **Exclusão Mútua**.

### Como resolver Race Conditions?

- **Proibir** que mais de um processo leia/escreva em recursos compartilhados concorrentemente;
- **Exclusão Mútua**: garantir que um processo não acesse a R.C. enquanto outro a estiver usando;
- Recorre-se aos **mecanismos de sincronização do S.O.**
- Válido também (e ainda mais crítico) para **threads**, pois compartilham os mesmos recursos dentro do processo.

### Regras para uma boa solução de programação concorrente

1. Dois ou mais processos **não podem estar simultaneamente** na região crítica;
2. **Não** se podem fazer suposições sobre velocidade/número de CPUs;
3. Um processo **fora** da R.C. não deve bloquear outro processo;
4. Um processo **não pode esperar infinitamente** para entrar na R.C.

## 4. Soluções para Exclusão Mútua (visão geral)

1. **Espera Ocupada** (Busy Waiting)
2. **Primitivas Sleep/Wakeup**
3. **Semáforos**
4. **Monitores**
5. **Passagem de Mensagem**

---

## 5. Espera Ocupada (Busy Waiting)

Constante checagem de um valor (loop) até que a entrada na R.C. seja permitida.

### 5.1 Desabilitar Interrupções

- Processo desabilita interrupções ao entrar na R.C. e reabilita ao sair.
- **Problema**: com interrupções desabilitadas, a CPU não chaveia entre processos (viola regra 2); processo pode esquecer de reabilitar (viola regra 4); em múltiplas CPUs, desabilitar em uma não impede acesso das outras.
- **Conclusão**: útil para o **kernel**, mas **não apropriado** para processos de usuário.

### 5.2 Variável de Trava (Lock)

- Variável `lock`: 0 = ninguém na R.C.; 1 = alguém na R.C.
- **Problema**: processo A lê `lock=0`; antes de alterar para 1, processo B é escalonado e também lê `lock=0` e seta 1; quando A retoma, também seta 1 → **ambos entram na R.C.** (viola regra 1). Mesmo problema do spooler.

### 5.3 Estrita Alternância (Strict Alternation)

- Variável `turn` (inicialmente 0) determina de quem é a vez de entrar na R.C.
- **Problema**: se o Processo B é mais rápido e sai da R.C., e o Processo A tenta reentrar mas `turn` ainda aponta para B (que está em região não-crítica) → A fica **bloqueado por B mesmo fora da R.C.** (viola regra 3).

### 5.4 Solução de Peterson e Instrução TSL (Test and Set Lock)

- Variável compartilhada usada para bloquear entrada quando outro processo está na R.C.
- **TSL** (instrução de hardware): `TSL RX, LOCK` — lê o conteúdo de `LOCK` em `RX` e armazena valor ≠ 0 em `LOCK` — **operação indivisível (atômica)**.
    - `LOCK == 0` → R.C. livre; `LOCK ≠ 0` → R.C. ocupada.
- Em sistemas multiprocessados, a instrução **trava o barramento de memória** durante sua execução, impedindo outras CPUs de acessarem a memória.

**Pseudocódigo:**

```asm
ENTRA_RC:
  TSL reg, flag   ; copia flag para reg e coloca 1 em flag
  CMP reg, 0      ; flag era zero?
  JNZ ENTRA_RC    ; se não (estava travada), volta ao laço
  RET

SAI_RC:
  MOV flag, 0     ; desliga flag
  RET
```

### Desvantagens da Espera Ocupada

- **Desperdiça tempo de CPU** (fica em loop);
- Pode causar **bloqueio perpétuo** (deadlock) em sistemas com prioridades.

---

## 6. Primitivas Sleep/Wakeup

Criadas para resolver o desperdício de CPU da espera ocupada — bloqueiam/desbloqueiam processos de fato.

- **Sleep**: chamada de sistema que **bloqueia** o processo chamador até que outro processo o "acorde".
- **Wakeup**: chamada de sistema que **acorda** um processo específico.
- Ambas recebem: o processo a manipular + um endereço de memória para casar Sleep com seu Wakeup correspondente.

### Problema Produtor/Consumidor (Bounded Buffer)

- Dois processos compartilham um **buffer de tamanho fixo**;
- **Produtor** insere dados; **Consumidor** retira dados;
- Variável `count` controla quantidade de dados no buffer.
    - **Produtor**: se `count` no máximo → dorme; senão insere e incrementa `count`.
    - **Consumidor**: se `count == 0` → dorme; senão retira e decrementa `count`.

### Restrições do problema (Buffer Circular)

- Produtor não excede a capacidade do buffer;
- Consumidor não consome mais rápido do que é produzido;
- Mensagens retiradas na **mesma ordem** em que inseridas;
- Exclusão mútua no acesso ao buffer.

### Problema: Sinal de Wakeup Perdido (Race Condition)

Sequência problemática:

1. Consumidor checa `count == 0` (buffer vazio);
2. Escalonador troca para o Produtor **antes** do consumidor dormir;
3. Produtor insere item, `count = 1`, e manda `wakeup` ao consumidor — **mas o consumidor ainda não está dormindo**, então o sinal é **perdido**;
4. Consumidor, ao rodar de novo, vê `count == 0` (desatualizado em sua lógica) e **dorme**;
5. Produtor eventualmente enche o buffer e também dorme;
6. **Ambos dormem para sempre** (deadlock).

### Solução: Bit de Wakeup (Wakeup Waiting Bit)

- Quando um `wakeup` é enviado a um processo que já está acordado, um **bit é setado (true)**;
- Ao tentar dormir, se o bit estiver ligado, ele é desligado e o processo **permanece acordado** (não dorme).
- **Limitação**: com vários pares de processos, seriam necessários **vários bits**, sobrecarregando o sistema.

---

## 7. Semáforos (E. W. Dijkstra, 1965)

- Variável **inteira** que armazena o número de sinais (`wakeups`) enviados/pendentes.
- Valor **0**: nenhum sinal armazenado (recurso ocupado); valor **positivo**: sinais armazenados (recurso livre).
- Duas primitivas **atômicas**: `down` (P / sleep) e `up` (V / wake) — nomes originais em holandês.

### Operações

- **down(semáforo)** — também chamado **P(s)**:
    - Se `semáforo > 0` → decrementa (`semáforo--`);
    - Se `semáforo == 0` → processo **bloqueia** (sem completar a operação).
- **up(semáforo)** — também chamado **V(s)**:
    - `semáforo++`;
    - Se há processos bloqueados nesse semáforo, **desbloqueia um deles** (o valor do semáforo permanece o mesmo nesse caso).

> Operações sobre semáforos são **atômicas** — podem ser implementadas como chamadas de sistema, desabilitando interrupções por um breve momento.

### Tipos de Semáforo

- **Semáforo Geral**: pode assumir qualquer valor inteiro não-negativo;
- **Semáforo Binário (Mutex)**: só assume valores **0 ou 1** — usado para exclusão mútua; o "recurso" é a própria região crítica.

### Semáforos e o Problema Produtor/Consumidor

Solução usa **três semáforos**:

- **full**: conta slots **ocupados** no buffer; inicia em **0**; resolve sincronização;
- **empty**: conta slots **vazios**; inicia com o **total de slots**; resolve sincronização;
- **mutex**: garante que produtor e consumidor não acessem o buffer ao mesmo tempo; inicia em **1**; é o semáforo binário (exclusão mútua).

### Problema: Erro de Programação pode gerar Deadlock

- Se a ordem das operações `down` for trocada incorretamente no produtor:
    - Se o buffer estiver cheio, o produtor bloqueia com `mutex = 0`;
    - O consumidor, ao tentar acessar o buffer, também tenta um `down(mutex)` e **também bloqueia**;
    - **Deadlock** — ambos ficam bloqueados para sempre.
- **Lição**: a **ordem correta** das operações de semáforo é crítica.

---

## 8. Monitores

Idealizado por **Hoare (1974)** e **Brinch Hansen (1975)**.

- **Monitor**: primitiva de **alto nível** para sincronizar processos.
    - Conjunto de **procedimentos, variáveis e estruturas de dados** agrupados em um único módulo/pacote.
- **Somente um processo pode estar ativo** dentro do monitor por vez; os demais ficam **bloqueados** até poderem entrar.

### Execução

- Ao chamar uma rotina do monitor, instruções iniciais testam se **outro processo já está ativo** dentro dele.
    - Se sim → processo novo é **bloqueado** até o outro sair;
    - Se não → processo executa normalmente as rotinas do monitor.

### Condition Variables (variáveis de condição)

- Indicam uma **condição** específica.
- Operações básicas:
    - **wait(condition)**: bloqueia o processo;
    - **signal(condition)**: "acorda" o processo bloqueado em `wait` naquela condição.
- **Importante**: variáveis de condição **não são contadores** — não acumulam sinais!
    - Se um `signal` é enviado **sem ninguém esperando**, o sinal é **perdido**.
    - Por isso, um `WAIT` deve **sempre vir antes** de um `SIGNAL` correspondente.

### Como evitar dois processos ativos ao mesmo tempo no monitor?

Duas abordagens clássicas:

1. **Hoare**: coloca o processo mais recente (que recebeu o `signal`) para rodar, **suspendendo** o processo que emitiu o sinal ("sinalizar e esperar");
2. **Brinch Hansen**: o processo que executa um `SIGNAL` deve **deixar o monitor imediatamente** — o comando `SIGNAL` deve ser o **último** de um procedimento do monitor.

> A abordagem de **Brinch Hansen é mais simples e fácil de implementar**.

### Exclusão Mútua Automática

- Garantida automaticamente pelo monitor: se o produtor, dentro de um procedimento do monitor, descobre que o buffer está cheio, ele pode executar `WAIT` com segurança, pois o **consumidor não estará ativo** dentro do monitor até que o `WAIT` termine e o produtor seja marcado como não-executável.

---

## 9. Limitações de Semáforos e Monitores

- Ambos são **boas soluções apenas para CPUs com memória compartilhada**;
- **Não são adequados** para sistemas **distribuídos**;
- Nenhuma das soluções permite troca de informação entre processos em **máquinas diferentes**;
- **Monitores dependem de suporte da linguagem de programação** — poucas linguagens os suportam nativamente.