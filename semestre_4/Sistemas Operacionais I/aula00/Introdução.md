-  23/09 - Primeira Prova;
-  23/11 - Segunda Prova;
-  Sobre a aplicação da prova:
	-  Livro texto
	- 2 folhas de sulfite **a mão**
-  *Livro Principal* : Sistemas Operacionais Modernos - Tanembaum

---
# Teoria para exercícios

## 1. Importância dos Sistemas Operacionais

O SO é o software base que **intermedia o hardware e os programas do usuário**, permitindo que aplicações sejam executadas sem que cada uma precise controlar diretamente CPU, memória, disco, etc. Sem ele, cada programa teria que reimplementar controle de hardware, tornando a computação inviável em termos de produtividade, segurança e portabilidade.

Principais motivos da sua importância:

- Abstrai a complexidade do hardware (oferece uma máquina virtual mais simples).
- Gerencia recursos compartilhados (CPU, memória, dispositivos) de forma eficiente e justa.
- Garante isolamento e proteção entre processos/usuários.
- Permite multiprogramação (vários programas "ao mesmo tempo").

## 2. O que é um Sistema Operacional

É um **conjunto de programas (software de sistema)** que gerencia os recursos de hardware de um computador e fornece serviços básicos para os programas de aplicação (software de usuário). Atua como intermediário entre o usuário/aplicações e o hardware.

Pode ser visto sob duas visões:

- **Visão do usuário (top-down):** máquina estendida/virtual — esconde detalhes do hardware e oferece uma interface mais simples e amigável.
- **Visão do sistema (bottom-up):** gerenciador de recursos — controla e aloca CPU, memória, dispositivos de E/S e arquivos entre os processos que competem por eles.

## 3. Sistema Operacional ≠ Sistema Computacional

**Não são a mesma coisa.**

- **Sistema Computacional (Sistema de Computação):** é o conjunto completo, composto por **hardware + software** (incluindo SO, aplicativos, usuários, dados). Envolve todos os componentes físicos e lógicos da máquina.
- **Sistema Operacional:** é **apenas uma camada de software** dentro do sistema computacional, responsável por gerenciar os recursos de hardware e servir de interface para os demais softwares.

Ou seja, o SO é um **componente** do sistema computacional, não o sistema como um todo.

## 4. O que é um Processo

Um processo é um **programa em execução**, incluindo:

- O código do programa (texto);
- O contador de programa (PC) e outros registradores da CPU;
- A pilha de execução (stack);
- O heap (memória dinâmica);
- Estado atual de execução;
- Recursos alocados (arquivos abertos, memória, etc).

Diferença fundamental: **programa é uma entidade passiva** (arquivo armazenado em disco, contendo instruções), enquanto **processo é uma entidade ativa** (o programa carregado em memória e sendo executado, com um estado dinâmico).

## 5. Atividades sob responsabilidade do Sistema Operacional

- **Gerência de processos:** criação, escalonamento (CPU scheduling), sincronização, comunicação e término de processos.
- **Gerência de memória:** alocação e liberação de memória para processos, paginação/segmentação, memória virtual.
- **Gerência de dispositivos de E/S:** controle de periféricos (discos, impressoras, teclado, etc.) por meio de drivers.
- **Gerência de arquivos (sistema de arquivos):** organização, armazenamento, nomeação, proteção e acesso a arquivos e diretórios.
- **Segurança e proteção:** controle de acesso a recursos, autenticação de usuários, isolamento entre processos.
- **Interface com o usuário:** shell (linha de comando) ou GUI (interface gráfica).
- **Contabilização e monitoramento** de uso de recursos (opcional em alguns SOs).

## 6. Estados de um Processo

Um processo, ao longo de sua execução, pode assumir os seguintes estados principais:

1. **Novo (New):** o processo está sendo criado.
2. **Pronto (Ready):** o processo está apto para execução, aguardando ser escalado para a CPU.
3. **Executando (Running):** o processo está sendo executado pela CPU no momento.
4. **Bloqueado/Espera (Waiting/Blocked):** o processo aguarda a ocorrência de algum evento (ex: término de uma operação de E/S) para continuar.
5. **Terminado (Terminated/Exit):** o processo finalizou sua execução.

Transições típicas:

- Novo → Pronto
- Pronto → Executando (escalonado pelo dispatcher)
- Executando → Pronto (preempção, fim do quantum)
- Executando → Bloqueado (espera por E/S ou evento)
- Bloqueado → Pronto (evento ocorreu)
- Executando → Terminado

## 7. O que é uma Thread

Uma thread (também chamada de **processo leve**) é uma **unidade básica de utilização da CPU** dentro de um processo. Um processo pode ter uma ou várias threads, que compartilham o mesmo espaço de endereçamento (memória, arquivos abertos, recursos), mas cada thread possui seu próprio:

- Contador de programa (PC);
- Conjunto de registradores;
- Pilha (stack) própria.

Threads permitem que um mesmo processo execute múltiplas tarefas de forma concorrente (ou paralela, em sistemas multicore).

## 8. Vantagens e Desvantagens de Threads vs Processos

**Vantagens do uso de threads:**

- **Menor custo de criação/destruição** — mais leves que processos.
- **Troca de contexto mais rápida** entre threads do que entre processos.
- **Compartilhamento fácil de dados** — como compartilham o mesmo espaço de memória, não precisam de mecanismos de IPC (comunicação entre processos).
- **Melhor uso de sistemas multiprocessados/multicore** (paralelismo real).
- **Maior responsividade** em aplicações (ex: uma thread trata E/S enquanto outra continua processando).

**Desvantagens do uso de threads:**

- **Falta de isolamento/proteção:** um erro em uma thread (ex: corrupção de memória) pode afetar todas as outras threads do mesmo processo.
- **Maior complexidade de sincronização:** por compartilharem dados, é necessário usar mecanismos como semáforos, mutexes, monitores para evitar condições de corrida (race conditions).
- **Dificuldade de depuração** — bugs de concorrência (deadlocks, race conditions) são mais difíceis de identificar e reproduzir.
- Se o SO não suportar bem múltiplas threads (ex: implementação em nível de usuário sem suporte do kernel), uma thread bloqueada pode bloquear todas as demais do processo.

## 9. O que significa um processo sofrer preempção

**Preempção** ocorre quando o sistema operacional **interrompe forçadamente a execução de um processo** que está no estado "Executando" (mesmo que ele ainda não tenha terminado ou solicitado a interrupção), para que a CPU seja repassada a outro processo.

Isso geralmente acontece por:

- Término do _quantum_ de tempo (fatia de tempo) alocado ao processo, em escalonamento por tempo compartilhado (_time-sharing_);
- Chegada de um processo de maior prioridade;
- Ocorrência de uma interrupção do sistema (ex: interrupção de E/S).

O processo preemptado volta ao estado **Pronto**, aguardando nova oportunidade de ser escalado. Isso contrasta com o escalonamento **não-preemptivo**, onde o processo só libera a CPU voluntariamente (ao terminar ou bloquear por E/S).

## 10. Relação entre Programa e Processo

- **Programa:** entidade **passiva e estática**. É um conjunto de instruções armazenado em disco (arquivo executável), sem estar em execução.
- **Processo:** entidade **ativa e dinâmica**. É o programa **em execução**, com estado próprio (contador de programa, registradores, pilha, memória alocada) que muda ao longo do tempo.

Relação: um processo **é criado a partir de um programa** quando este é carregado na memória para execução. Um mesmo programa pode gerar **vários processos diferentes e independentes** simultaneamente (ex: abrir várias instâncias de um mesmo aplicativo), cada um com seu próprio espaço de memória e estado.