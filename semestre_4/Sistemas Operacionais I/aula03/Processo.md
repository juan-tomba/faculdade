## Definição de Processo

- É um programa em execução, incluindo os valores correntes do contador de programa, registradores e variáveis.
- O conceito de **processo é dinâmico**, em contraposição ao conceito de **programa**, que é **estático**.
- Nem sempre um programa equivale a apenas um processo.
- Em sistemas que permitem **reentrância**, o código de um programa pode gerar vários processos.

---

## Reentrância

- Capacidade de um código executável (reentrante) ser **compartilhado por diversos usuários**, exigindo que apenas **uma cópia do programa** esteja na memória.
- Permite que cada usuário esteja em um ponto diferente do código reentrante, manipulando **dados próprios**, exclusivos de cada usuário.
- Ou seja: o código é único e compartilhado, mas cada processo (A, B...) tem seus próprios dados e seu próprio ponto de execução dentro desse código.

---

## Processo

- Caracterizado por programas em execução.
- Cada processo possui:
    - **Programa** (instruções que serão executadas)
    - **Espaço de endereço de memória** (mínimo e máximo)
    - **Contextos de software**: atributos

> O Sistema Operacional gerencia todos os processos fazendo uso do **Bloco de Controle de Processos (BCP)**.

### Segmentos de um processo

Basicamente, um processo possui três segmentos:

- **Texto**: código do(s) programa(s)
- **Dados**: as variáveis
- **Pilha de execução**: controla a execução do processo

### Processo — Contextos

Um processo é dividido em dois grandes contextos:

- **Contexto de Hardware**: registradores gerais, registrador PC (_program counter_), registrador SP (_stack pointer_), registrador de status
- **Contexto de Software**: nome, PID, owner (UID), prioridade de execução, data/hora de criação, tempo de processador, quotas, privilégios
- **Espaço de Endereçamento**: endereços de memória principal alocados

---

## Bloco de Controle de Processo (BCP)

- Contém informações sobre o processo.
- Também conhecido por **Bloco de Controle de Programa** ou **Descritor de Processo**.
- É uma estrutura de dados contendo informações importantes sobre o processo, incluindo:
    - A identificação do processo
    - O estado do processo
    - O nome do processo
    - A prioridade do processo
    - Registradores
    - Limites de memória
    - Ponteiros para a localização do processo na memória ou no disco
    - Lista de arquivos abertos
    - Contador de programa
    - Área de salvamento dos registradores, etc.

No sistema, cada processo é representado por seu resumo (o BCP), que se relaciona com: Usuário, S.O., Memória Principal, UCP e disco.

---

## Processo — Resultado do S.O.: Executar Programas

Fluxo de execução de um programa:

```
Editor → Program Source (foo.c)
       → Compiler and Linker → Executable (a.out: data + instructions)
       → OS Loader → carregado na memória (OS / stack / heap / data / instructions)
       → Processor (PC + registers) executa as instruções
```

---

## Processo — Implementação

### Tabela de Processos

- Cada processo possui **uma entrada** na tabela de processos.
- Cada entrada possui um **ponteiro para o BCP** (ou descritor) do processo.
- O BCP possui todas as informações do processo: contextos de hardware, software, endereço de memória.

```
Tabela de processos → BCP-P1
                     → BCP-P2
                     → ...
                     → BCP-Pn
```

### Algumas informações do BCP (exemplo — modelo Unix-like)

|Process management|Memory management|File management|
|---|---|---|
|Registers|Pointer to text segment|Root directory|
|Program counter|Pointer to data segment|Working directory|
|Program status word|Pointer to stack segment|File descriptors|
|Stack pointer||User ID|
|Process state||Group ID|
|Priority|||
|Scheduling parameters|||
|Process ID|||
|Parent process|||
|Process group|||
|Signals|||
|Time when process started|||
|CPU time used|||
|Children's CPU time|||
|Time of next alarm|||

---

## Processo — Criação

Principais eventos que causam a criação de um processo:

- Inicialização do Sistema
- Execução de uma chamada ao sistema de criação de processo por um processo em execução
- Uma requisição de usuário para a criação de um novo processo
- Início de um _job_ em lote

### Unix — `fork`

- Cria processo **pai** e processo **filho** com **mesmo endereçamento**
- Depois o processo filho tem endereçamento **separado**

### Windows — `CreateProcess`

- Cria processo pai e processo filho com mesmo endereçamento **SEMPRE**

---

## Processo — Hierarquia e Escalonamento

- Um processo pode resultar na execução de outros processos, chamados de **processos filhos**.
- Características para a hierarquia de processos:
    - Comunicação (interação) e Sincronização
    - Segurança e proteção
    - Uma árvore de no máximo **três níveis**
- **Escalonadores de processos**: processo (do S.O.) que escolhe qual será o processo a ser executado
    - Diversas técnicas para escalonamento de processos
- Comunicação e sincronismo entre processos

---

## Processo — Chamada de Sistema (_System Call_)

- Interface de programação fornecida pelo S.O.
- Normalmente escrita em linguagem de alto nível (C, C++, Java)
- Aplicações normalmente utilizam uma **API** (_Application Program Interface_) que encapsula o acesso direto às _system calls_
- APIs mais utilizadas:
    - **Win32 API** — Windows
    - **POSIX API** — praticamente todas as versões UNIX
    - **JAVA API** — _Java Virtual Machine_ (JVM)

### Motivos para usar APIs em vez de _System Calls_ diretamente

- **Portabilidade** — independência da plataforma
- Esconder complexidade inerente às _system calls_
- Acréscimo de funcionalidades que otimizam o desempenho
- O acesso às _system calls_ está implementado em bibliotecas carregadas com as aplicações

### Exemplo — sequência de _system calls_ para copiar um arquivo

1. Adquirir nome do arquivo de entrada (prompt + input)
2. Adquirir nome do arquivo de saída (prompt + input)
3. Abrir arquivo de entrada (aborta se não existir)
4. Criar arquivo de saída (aborta se já existir)
5. _Loop_: ler do arquivo de entrada → escrever no arquivo de saída, até a leitura falhar
6. Fechar arquivo de saída
7. Escrever mensagem de conclusão / terminar normalmente

### Exemplo — `ReadFile()` (Win32 API)

```
BOOL ReadFile(
    HANDLE       file,
    LPVOID       buffer,
    DWORD        bytesToRead,
    LPDWORD      bytesRead,
    LPOVERLAPPED ovl
);
```

- `HANDLE file` — arquivo a ser lido
- `LPVOID buffer` — buffer onde os dados serão lidos/escritos
- `DWORD bytesToRead` — número de bytes a serem lidos
- `LPDWORD bytesRead` — número de bytes lidos na última leitura
- `LPOVERLAPPED ovl` — indica se está sendo usado I/O sobreposto (_overlapped_)

### Exemplo — API Unix Standard (`read`)

```c
#include <sys/types.h>
#include <unistd.h>

int read(int fd, char *buf, size_t count);
```

Lê até `count` bytes do descritor de arquivo `fd` para o buffer `buf`. Em sucesso, retorna o número de bytes lidos (zero indica fim de arquivo); em erro, retorna -1 e `errno` é definido apropriadamente.

### Como funciona (mecanismo)

- A cada _system call_ está associado um **número**.
- A interface mantém uma **tabela** com o endereço de cada _system call handler_, indexada pelo número da _system call_.
- Por meio dessa tabela, o respectivo _handler_ é invocado no **kernel**:
    - Os parâmetros são transferidos para o kernel
    - Uma vez executado, o resultado e os parâmetros de retorno são transferidos de volta para o programa usuário
- A aplicação que invoca a _system call_ **não precisa saber como ela é implementada** — só precisa obedecer à sintaxe da API e esperar o resultado.
- Os detalhes da interface do sistema são escondidos pela API (geridos pela **biblioteca run-time**, incluída na aplicação na compilação/carregamento do executável).

### Fluxo: user application → kernel

```
user application → open() [user mode]
                 → system call interface
                 → [kernel mode] tabela de syscalls → implementação de open() → return
```

### Transição para as _Syscalls_ em Linux

```
Application → call read()
User Space:  C library → read() wrapper
Kernel Space: system_call() → sys_read()
```

### Invocação direta de _System Call_ (Assembly)

Exemplo de programa em Assembler que invoca `write()` e `exit()` via instrução `int 0x80` (interrupção de software).

### Otimização em CPUs Intel modernas

- A partir do Pentium II: instruções **`sysenter`** e **`sysexit`** permitem realizar _system calls_ mais rapidamente, sem passar por uma interrupção de software.
- O kernel Linux utiliza essas instruções preferencialmente a partir da versão 2.6.
- Invocadas via código _assembler_ colocado pelo kernel em uma página específica de todos os processos: **vDSO** (_virtual dynamic shared object_).
- Ponto de entrada: `kernel_vsyscall`.

### Exemplo — `printf()` em C

Um programa em C que invoca `printf()` (função de biblioteca), que por sua vez chama a _system call_ `write()`:

```
main() → printf("Greetings") [user mode / standard C library]
       → write() [kernel mode] → write() system call
```

---

## Modos de Acesso do Processador

- **Modo Usuário**
- **Modo Kernel** (ou Supervisor, ou Núcleo)
- Determinados por um conjunto de bits no registrador de status do processador — **PSW** (_Program Status Word_)
    - O hardware verifica, por meio desse registrador, se a instrução pode ou não ser executada pela aplicação
- Protege o próprio kernel do S.O. na RAM contra acessos indevidos

### Modo Usuário

- Aplicações **não têm acesso direto** aos recursos da máquina (hardware)
- Só pode executar **instruções sem privilégio**, com acesso reduzido de instruções
- Motivo: garantir a **segurança** e a **integridade** do sistema

### Modo Kernel

- Aplicações têm **acesso direto** aos recursos da máquina (hardware)
- **Operações com privilégios**
- Acesso ao **conjunto total de instruções**
- Apenas o S.O. tem acesso às instruções privilegiadas

### Transição entre modos

- Se uma aplicação precisa executar uma instrução privilegiada, ela realiza uma **chamada de sistema**, que altera o modo usuário para o modo kernel.
- **Chamadas de sistema são a porta de entrada para o modo kernel**: são a interface entre os programas de usuário (modo usuário) e o S.O. (modo kernel).
- As chamadas diferem de S.O. para S.O., mas os conceitos são similares independentemente do S.O.

### TRAP

- **TRAP**: instrução que permite o acesso ao modo kernel.
- Exemplo (Unix): `count = read(fd, buffer, nbytes);`
    - Parâmetros: arquivo a ser lido, ponteiro para o buffer, bytes a serem lidos.
    - ⚠️ **O programa sempre deve checar o retorno da chamada de sistema para saber se algum erro ocorreu!**

### Diagrama do fluxo de uma chamada `read`

```
Espaço do Usuário:
  Chamada ao Procedimento READ: empilha nbytes → empilha &buffer → empilha fd → comando read → incrementa SP
  Biblioteca do Procedimento READ: comando read inserido no registro → TRAP → retorno

Kernel SO:
  Dispatch → Tabela de ponteiros para Chamadas → Manipulador de Chamadas
```

---

## Exemplos de Chamadas de Sistema

- **Gerenciamento de processos**: `Fork` (Unix) / `CreateProcess` (WIN32) — cria processo
- **Gerenciamento de diretórios**: `Mount` — monta um diretório
- **Gerenciamento de arquivos**: `close` (Unix) / `CloseHandle` (WIN32) — fecha um arquivo
- **Outros tipos**: `chmod` — modifica permissões

---

## Processo — Término

Condições que podem provocar o término de um processo:

- **Saída normal** (voluntária)
- **Saída por erro** (voluntária)
- **Erro fatal** (involuntária)
- **Destruído por outro processo** (involuntária)

### Término normal (voluntária)

- A tarefa a ser executada é finalizada.
- Chamadas: `exit` (UNIX) e `ExitProcess` (Windows)

### Término com erro (voluntária)

- O processo sendo executado não pode ser finalizado.
- Ex.: `gcc filename.c`, mas o arquivo `filename.c` não existe.

### Término com erro fatal (involuntária)

- Erro causado por algum **bug** no programa:
    - Divisão por 0 (zero)
    - Referência à memória inexistente ou não pertencente ao processo
    - Execução de uma instrução ilegal

### Término causado por outro processo (involuntária)

- Chamadas: `kill` (UNIX) e `TerminateProcess` (Windows)