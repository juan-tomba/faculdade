## Na sua concepção, qual a importância dos Sistemas Operacionais?

- Sistemas operacionais são feitos para interligar o hardware e o usuário, Sem ele, todo programa precisaria ser escrito para gerenciar diretamente os componentes físicos da máquina (processador, memória, discos, periféricos). Ele abstrai essa complexidade do hardware, criando um ambiente onde os programas podem ser executados de forma conveniente, além de garantir que os recursos limitados da máquina sejam distribuídos de maneira justa, eficiente e segura.

## O que você entende por Sistema Operacional?

- É o software principal que gerencia o hardware do computador. Ele pode ser definido por duas funções principais:
	- **Gerenciador de recursos:** Aloca tempo de CPU, espaço de memória e acesso a dispositivos de Entrada/Saída para os programas que os solicitam.
	- **Programa de controle:** Controla a execução dos programas dos usuários para evitar erros e o uso indevido do computador, fornecendo uma interface padrão (System Calls) para as aplicações.

## Para você, Sistema Operacional é o mesmo que Sistema Computacional?

- Não. Um **Sistema Computacional** é o conjunto completo composto por quatro componentes: Hardware, Sistema Operacional, Programas de Aplicação e Usuários. O Sistema Operacional é apenas uma parte desse todo — especificamente, a camada de software que fica logo acima do hardware, orquestrando o funcionamento geral para que as aplicações e os usuários possam utilizar a máquina.

## O que é um processo?

- De forma simples, é um **programa em execução**. Enquanto um programa é apenas um arquivo no disco, um processo é uma entidade ativa. Ele contém não apenas o código (seção de texto), mas também o estado atual da execução (representado pelo _Program Counter_ e pelos registradores), a pilha de execução (_stack_ - com variáveis locais e endereços de retorno), a seção de dados (variáveis globais) e o _heap_ (memória alocada dinamicamente).

## Quais atividades são responsabilidade de um Sistema Operacional no seu ponto de vista?

- **Gerenciamento de Processos:** Criação, exclusão, escalonamento e sincronização de processos/threads.
- **Gerenciamento de Memória:** Controle de quais partes da memória estão em uso, alocação/desalocação e paginação (memória virtual).
- **Gerenciamento de Arquivos:** Mapeamento de arquivos na mídia de armazenamento e organização em diretórios.
- **Gerenciamento de E/S (I/O):** Comunicação com drivers de dispositivos físicos.
- **Segurança e Proteção:** Garantir que processos não invadam o espaço de memória de outros processos e controlar permissões de acesso.

## Quais são os estados que um processo pode assumir?

- **Novo (New):** O processo está sendo criado.
- **Pronto (Ready):** O processo está na fila, esperando para ser atribuído a um processador (CPU).
- **Executando (Running):** As instruções do processo estão sendo ativamente processadas pela CPU.
- **Em Espera / Bloqueado (Waiting/Blocked):** O processo está esperando que algum evento ocorra (como o término de uma operação de leitura no disco).
- **Terminado (Terminated):** O processo finalizou sua execução.

## O que é uma Thread?

- Uma _thread_ (ou fluxo de controle) é a unidade básica de utilização da CPU. Um processo tradicional possui uma única thread de controle, mas processos modernos costumam ter múltiplas threads. Uma thread possui seu próprio ID, contador de programa (_Program Counter_), conjunto de registradores e pilha (_stack_). No entanto, ela **compartilha** com as outras threads do mesmo processo a seção de código, a seção de dados e os recursos do SO (como arquivos abertos).

## Quais são as vantagens e desvantagens do uso de threads em relação ao uso de processos?

- **Vantagens:**
    - **Economia:** Criar threads e alternar o contexto entre elas é muito mais rápido e consome menos memória do que fazer isso com processos.
    - **Compartilhamento de Recursos:** Threads no mesmo processo compartilham memória naturalmente, facilitando a comunicação sem precisar de complexas chamadas de IPC (_Inter-Process Communication_).
    - **Responsividade:** Em interfaces gráficas ou servidores web, uma thread pode ser bloqueada (ex: carregando dados) enquanto outra continua respondendo ao usuário.

- **Desvantagens:**
    - **Vulnerabilidade Compartilhada:** Se uma thread falhar ou cometer um erro crítico (como tentar acessar memória inválida), todo o processo (e as outras threads dentro dele) será derrubado.
    - **Sincronização:** Como a memória é compartilhada, programar com threads exige cuidado extra (uso de _mutexes_ e semáforos) para evitar condições de corrida (_race conditions_) e _deadlocks_.

## O que significa um processo sofrer preempção?

- **Preempção** é o ato do Sistema Operacional interromper forçadamente um processo que está atualmente no estado "Executando" e movê-lo de volta para o estado "Pronto". Isso geralmente ocorre porque o tempo limite alocado para aquele processo (o _quantum_ ou fatia de tempo) se esgotou, ou porque um processo de prioridade mais alta entrou na fila de prontos. É o mecanismo que permite a ilusão de que o computador está rodando vários programas simultaneamente (multitarefa preemptiva).

## Qual a relação entre programa e processo?

- A distinção clássica é entre passivo e ativo. Um **programa** é uma entidade passiva: um arquivo contendo um conjunto de instruções armazenado no disco (um executável). Um **processo** é uma entidade ativa: é o programa quando carregado na memória principal, com recursos do sistema alocados a ele (CPU, registradores, memória) e em plena execução. Um único programa pode gerar vários processos diferentes (por exemplo, abrir três janelas independentes do mesmo navegador web gera três processos distintos do mesmo programa).