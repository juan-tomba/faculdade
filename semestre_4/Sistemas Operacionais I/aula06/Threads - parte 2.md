## 1. O que são Threads (revisão/aprofundamento)

- Definição clássica: um único **contexto de execução** (descreve sua representação).
- Definição alternativa (também válida): uma **única sequência de execução** que representa uma tarefa programada separadamente.
- **Threads são um mecanismo de simultaneidade.**
- **Proteção é um conceito ortogonal** a threads — um **domínio de proteção** pode conter um ou vários threads.

## 2. Motivação para Threads

Sistemas precisam lidar com **Várias Coisas ao Mesmo Tempo (VCMT)**:

- **S.O.**: processos, interrupções, manutenção do sistema em segundo plano;
- **Servidores em rede**: múltiplas conexões simultâneas;
- **Programas paralelos**: melhor desempenho;
- **Interfaces de usuário**: capacidade de resposta durante computação;
- **Programas ligados à rede/disco**: ocultar latência de rede/disco.

> **Threads são a unidade de simultaneidade fornecida pelo S.O.** Cada thread pode representar uma coisa/tarefa.

## 3. Concorrência ≠ Paralelismo

- **Concorrência (simultaneidade)**: lidar com VCMT.
- **Paralelismo**: fazer várias coisas _de fato_ ao mesmo tempo.
- Exemplo: dois threads em um sistema **monocore**:
    - Executam **concorrentemente**... mas **não em paralelo**.
- Cada thread gerencia uma tarefa separada, mas essas tarefas **não são necessariamente executadas simultaneamente**.

## 4. Multiprocessamento vs Multiprogramação vs Multithreading

|Termo|Significado|
|---|---|
|**Multiprocessamento**|Vários núcleos (hardware)|
|**Multiprogramação**|Vários trabalhos/processos|
|**Multithreading**|Vários threads/processos|

- Executar "dois threads simultaneamente" significa: o **escalonador é livre para executar threads em qualquer ordem e intercalação**.

## 5. Exemplo "bobo" de Threads (sem threads)

```c
main() {
    ComputePI("pi.txt");
    PrintClassList("classlist.txt");
}
```

- **Comportamento**: o programa **nunca** imprimiria a lista de aulas, pois `ComputePI` nunca termina (loop infinito, por exemplo).

## 6. Adicionando Threads

```c
main() {
    create_thread(ComputePI, "pi.txt");
    create_thread(PrintClassList, "classlist.txt");
}
```

- `create_thread`: gera um novo thread executando o procedimento fornecido.
- Deve se comportar **como se outra CPU** estivesse executando o procedimento.
- Agora, a lista de classes **seria de fato exibida** — as duas tarefas alternam entre CPU1/CPU2 ao longo do tempo (mesmo sem paralelismo real, a CPU alterna entre elas).

## 7. Mais Motivações Práticas — Latências (Jeff Dean)

Números que todo programador deveria saber (aproximados):

|Operação|Tempo aproximado|
|---|---|
|L1 cache reference|0.5 ns|
|Branch mispredict|5 ns|
|L2 cache reference|7 ns|
|Mutex lock/unlock|25 ns|
|Main memory reference|100 ns|
|Compress 1K bytes with Zippy|3.000 ns|
|Send 2K bytes over 1 Gbps network|20.000 ns|
|Read 1 MB sequentially from memory|250.000 ns|
|Round trip within same datacenter|500.000 ns|
|**Disk seek**|**10.000.000 ns**|
|**Read 1 MB sequentially from disk**|**20.000.000 ns**|
|**Send packet CA→Netherlands→CA**|**150.000.000 ns**|

> **Lição**: E/S (disco, rede) é **ordens de magnitude mais lenta** que operações de CPU/memória. Por isso, deve-se **lidar com E/S em threads separadas**, evitando bloquear outros processos/tarefas.

## 8. Thread — Estados

Um thread está em um dos três estados:

- **EXECUTANDO**: rodando na CPU;
- **PRONTO**: elegível para execução, mas não em execução no momento;
- **BLOQUEADO**: inelegível para execução (ex: esperando E/S).

> Se um thread espera uma E/S terminar → S.O. o marca como **BLOQUEADO**. Quando a E/S termina → S.O. o marca como **PRONTO**.

## 9. Exemplo Melhorado de Threads

```c
main() {
    create_thread(ReadLargeFile, "pi.txt");
    create_thread(RenderUserInterface);
}
```

- **Comportamento**: a aplicação continua **respondendo à entrada do usuário** enquanto **lê o arquivo em segundo plano** (background).

## 10. Programas Multithread

- Compilar um programa C e executar → cria um **processo** rodando aquele programa.
- Inicialmente, o processo tem **um único thread** em seu espaço de endereço (código, globais, etc. conforme o executável).

**P: Como tornar um processo multithread?** **R:** Assim que o processo inicia, ele emite **chamadas de sistema (syscalls)** para criar novos threads. Esses novos threads são parte do processo: **compartilham seu espaço de endereço**.

## 11. Thread — Syscalls

- Muita gente nunca "viu" diretamente uma syscall de thread:
    - A **chamada de sistema** é normalmente um problema/detalhe da **biblioteca do S.O.**;
    - O **runtime da linguagem** usa a **biblioteca do sistema operacional** para isso.
- Camadas envolvidas: Aplicação/Serviço → Portable OS Library → **System Call Interface** → Portable OS Kernel → Hardware (x86, PowerPC, ARM, drivers, etc.)

## 12. Spoiler — pthreads (POSIX Threads)

Principais funções da API `pthread`:

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                    void *(*start_routine)(void*), void *arg);
```

- A thread é criada executando `start_routine` com `arg` como seu único argumento.
- O `return` é implícito à chamada `pthread_exit`.

```c
void pthread_exit(void *value_ptr);
```

- Termina a thread e torna `value_ptr` disponível para quem for esperar (join) com sucesso.

```c
int pthread_join(pthread_t thread, void **value_ptr);
```

- Suspende a execução da thread chamada **até que a thread alvo termine**.
- Se o retorno de `value_ptr` não for NULL, o valor passado para `pthread_exit()` pela thread terminando fica disponível na localização referenciada por `value_ptr`.

> Referência: `man pthread` — https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html

### O que acontece quando `pthread_create(...)` é chamado?

**Na biblioteca (nível usuário):**

```
int pthread_create(...) {
    Faça algo normal como uma fn.
    asm code ... syscall # into %eax
    put args into registers %ebx, ...
    special trap instruction
    get return values from regs
    Faça algo normal mais um pouco como uma fn.
}
```

**No kernel (após o trap):**

```
get args from regs
dispatch to system func
Do the work to spawn the new thread
Store return value in %eax
```

## 13. Exemplo: Criação de Múltiplos Threads (loop com pthread_create)

Um programa em C típico:

- Inclui `<pthread.h>`;
- Define uma função de thread (`threadfun`) que imprime seu ID;
- No `main`, faz um **loop** criando `N` threads com `pthread_create`, cada uma recebendo um índice/argumento;
- Ao final, faz um **loop de `pthread_join`** para aguardar todas as threads terminarem.

## 14. Padrão Fork-Join

- O **thread principal** cria (**bifurca** — _fork_) uma coleção de **sub-threads**, passando-lhes argumentos para trabalhar;
- ...e depois **se junta** (_join_) a eles, **coletando os resultados**.

```
        create
          |
     /----+----\
    /     |     \
 thread thread thread   (executam em paralelo/concorrência)
    \     |     /
     \----+----/
          |
         join
          |
         exit
```

## 15. Abstração de Threads

- **Ilusão** (visão do programador): número **infinito** de processadores — cada thread parece ter seu próprio processador dedicado.
- **Realidade física**: threads executam com **"velocidade" variável** — o número de processadores reais é limitado; algumas threads ficam **rodando** (Running) e outras **prontas** (Ready), aguardando a CPU.
- **Consequência**: os programas devem ser **projetados para funcionar corretamente com qualquer escalonamento/programação** possível.

## 16. Visão do Programa vs Visão do Programador

- O **programador** escreve o código pensando em uma sequência linear e determinística de instruções (ex.: `x = x+1; y = y+x; z = x+5y;`).
- Na **execução real**, o escalonador pode **suspender** a thread no meio da sequência, executar outra(s) thread(s), e depois **retomar** a execução — gerando **múltiplas execuções possíveis** para o mesmo código.
- Isso mostra por que a ordem de operações entre threads **não é garantida** e pode variar a cada execução.

## 17. Correções com Threads Simultâneos

### Não determinismo

- O escalonador pode executar threads em **qualquer ordem**;
- O escalonador pode **alternar** entre threads a qualquer momento;
- Isso pode tornar o **teste** de programas concorrentes **muito difícil**.

### Tipos de Threads (quanto ao compartilhamento de estado)

- **Threads Independentes**:
    - Nenhum estado compartilhado com outras threads;
    - Condições **determinísticas e reproduzíveis**.
- **Threads Cooperantes**:
    - **Estado compartilhado** entre várias threads.

### Meta

> **Correção por Projeto** (Correctness by Design) — o programa deve ser projetado para estar correto independentemente da ordem/intercalação de execução das threads.

