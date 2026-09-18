## 1. Definição

- **Thread** (ou **processo leve**): unidade básica de utilização da CPU.
    - Composta por: **contador de programa**, **conjunto de registradores** e **pilha de execução**.
- Threads pertencem a um processo e **compartilham** os segmentos de código, dados e recursos alocados ao processo pelo S.O.
- O conjunto de threads de um processo é chamado **Task**.
- Um processo tradicional possui uma Task com apenas **1 thread**. _(Silberschatz)_

## 2. Estados de uma Thread

- **Nova** → `new Thread()`
- **Pronta** → via `start()` ou retorno do escalonador
- **Executando** → escolhida pelo escalonador
- **Esperando** → `sleep(tempo)`, `wait()`, solicitação de I/O
- **Morta** → método `run()` termina

```
Nova --new Thread()--> Pronta --Escalonador--> Executando
Executando --yield()/Escalonador--> Pronta
Executando --sleep/wait/I-O--> Esperando --evento ocorre--> Pronta
Executando --run() acaba--> Morta
```

## 3. Por que Threads foram criadas?

Dois objetivos principais:

- **Facilidade de comunicação** entre unidades de execução;
- **Redução do esforço de manutenção** dessas unidades.

> A ideia: aproveitar o esforço de criação de um processo (espaço de endereçamento lógico + BCP) para várias unidades executáveis, ganhando facilidade de comunicação entre elas.

## 4. Processo vs Thread

||Processo|Thread|
|---|---|---|
|Espaço de endereço|Próprio|Compartilhado com outras threads do mesmo processo|
|Linhas de controle|Única|Múltiplas|
|Recursos particulares|—|PC, registradores, pilha|
|Recursos compartilhados|—|Espaço de endereço (variáveis globais, arquivos etc.)|

### Itens por Processo vs por Thread

|Itens por Processo|Itens por Thread|
|---|---|
|Espaço de endereçamento|Contador de programa|
|Variáveis globais|Registradores (contexto)|
|Arquivos abertos|Pilha|
|Processos filhos|Estado|
|Alarmes pendentes||

**Analogia**: _multithreading_ (vários threads em paralelo em um processo) ≈ vários processos em paralelo em um computador.

## 5. Características de uma Thread

- Similar a um programa sequencial: tem início, execução e fim, com um único ponto de execução por vez.
- **Não é um programa** — não roda sozinha, existe no contexto de uma aplicação.
- Uma aplicação pode ter vários pontos de execução distintos, cada um representado por uma thread.
- Processo com uma única thread = conceito tradicional de processo (nada novo).
- O benefício real aparece com **múltiplas threads em um mesmo processo**, executando simultaneamente e realizando tarefas diferentes → dá **ideia de paralelismo**.

### Exemplo: navegador HotJava

Executa simultaneamente (para o usuário): carregar/executar applets, animação, som, exibir figuras, rolagem de tela, carregar nova página — tudo via múltiplas threads, mesmo com um único processador.

## 6. Ausência de Proteção entre Threads

- **Não há proteção entre threads** (é desnecessário).
- Como cada thread acessa qualquer endereço de memória dentro do espaço de endereçamento do processo, uma thread pode **ler, escrever ou apagar a pilha de outra thread**.

## 7. Razões para Existência de Threads

- Múltiplas atividades "ao mesmo tempo", algumas podem bloquear periodicamente;
- Threads são **mais fáceis de gerenciar** que processos (não possuem recursos próprios — o processo é que tem);
- **Desempenho**: com muita E/S, threads permitem sobreposição de atividades, acelerando a aplicação;
- **Paralelismo real** em sistemas com múltiplas CPUs.

### Exemplos de uso

- **Servidor de arquivos**: usa cache; se uma thread bloqueia esperando transferência de arquivo, outras threads continuam atendendo requisições.
- **Navegador Web**: múltiplas conexões simultâneas para baixar várias figuras da página → melhora desempenho.
- **Editor de texto**: diferentes threads para diferentes tarefas (exibição, formatação, salvamento, etc.), especialmente útil com múltiplos capítulos/arquivos.
- **Pipeline em processadores**: análogo — não espera terminar uma unidade para começar a próxima (teclado → threads → disco).

## 8. Benefícios das Threads

- **Capacidade de resposta**: aplicações interativas (ex: servidor WEB);
- **Compartilhamento de recursos**: mesmo endereçamento, memória, recursos;
- **Economia**: criar e chavear threads é mais barato que processos;
- **Utilização de arquiteturas multiprocessador**: processamento paralelo real.

## 9. Tipos de Threads

### 9.1 Threads em Modo Usuário

- Implementadas por **bibliotecas no nível do usuário**.
- Criação e escalonamento realizados **sem conhecimento do kernel**.
- **Run-time system** (sistema supervisor): coleção de procedimentos que gerenciam as threads.
- Cada processo tem sua própria **tabela de threads**.

**Vantagens:**

- Alternância de threads mais rápida que no kernel;
- Menos chamadas ao kernel;
- Cada processo pode ter seu próprio algoritmo de escalonamento.

**Desvantagem:**

- Se uma thread faz uma chamada bloqueante ao sistema, **todo o processo é bloqueado**.

### 9.2 Threads em Modo Kernel

- Suportadas **diretamente pelo S.O.**
- Criação, escalonamento e gerenciamento feitos pelo **kernel**.
- Tabela de threads e tabela de processos **separadas**, ambas implementadas no kernel.

**Vantagens:**

- Processo inteiro **não** é bloqueado se uma thread fizer chamada bloqueante.

**Desvantagem:**

- Gerenciamento mais caro devido às chamadas de sistema na alternância entre modo usuário e modo kernel.

## 10. Modelos de Multithreading

|Modelo|Descrição|Paralelismo real?|Exemplos de SO|
|---|---|---|---|
|**Muitos-para-um**|Muitas threads de usuário → 1 thread de kernel|Não|—|
|**Um-para-um**|Cada thread de usuário → 1 thread de kernel|Sim|Linux, Windows, OS/2, Solaris 9|
|**Muitos-para-muitos**|N threads de usuário → M threads de kernel (M ≤ N)|Sim|Solaris (até v8), HP-UX, Tru64 UNIX, IRIX|

## 11. Manipulação de Threads

- **Estados**: executando, pronta, bloqueada.
- **Comandos (API)**:
    - `Thread_create`
    - `Thread_exit`
    - `Thread_wait`
    - `Thread_yield` — permite que a thread desista voluntariamente da CPU.

## 12. Por que usar Threads? (Resumo)

- **Simplifica o modelo de programação**: decomposição de uma aplicação com múltiplas atividades em múltiplas threads;
- **Gerenciamento mais simples** que processo (sem recursos "atachados") — criação de thread pode ser **~100x mais rápida** que criação de processo;
- **Melhoria de desempenho**, especialmente quando a thread é orientada a E/S;
- **Útil em sistemas com múltiplas CPUs** (paralelismo real).

## 13. Fun Facts

- Os threads NÃO saem na mesma ordem que foram criados (a primeira pode acabar mais rapido ou não)
- Se executarmos o programa novamente, o RESULTADO PODE MUDAR