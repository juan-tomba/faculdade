-  SO: Programa que atua como intermediário entre os usuários e o hardware
-  Duas visões do SO:
	- Máquina estendida (top down)
		- torna tarefas de baixo nível fáceis para o usuário
	- Gerenciador de recursos (Bottom-up)
		- gerencia os dispositivos do computador
> dizer que o SO oferece ao usuário uma “máquina virtual” mais conveniente que o hardware cru é correto.
- **Multiprogramação:** divide a memória em várias partes e mantém **vários jobs/programas na memória ao mesmo tempo**, alternando a CPU entre eles.
- **Spooling:** usa **disco como uma fila/buffer** para armazenar dados que serão usados por dispositivos lentos, como impressora. Ex.: vários programas mandam imprimir → os arquivos ficam no disco → a impressora processa um por vez.
- **Time-sharing:** divide o **tempo da CPU em pequenos intervalos (quantum)** e dá um pouco para cada processo, permitindo que **vários usuários/processos interajam simultaneamente**.
- Sistema de computador = hardware + programas de sistema + programas de aplicação
-  *Kernel (supervisor) x usuário*
- **kernel**
	- acesso direto ao hardware
	- conjunto total de instruções
	- Só o SO acessa instruções privilegiadas
- **usuário**
	- acesso só a certas regiões de memória
	- precisa pedir ao SO
	- não acessa dispositivos diretamente

## Tipos de SO

1. quanto ao compartilhamento de hardware:
	-  *Monoprogramáveis* - um único programa ativo, que fica na memória até terminar
	- *Multiprogramáveis* - vários programas na memória; aumento de produtividade e redução de custos
2. Quanto á interação permitida
	- Batch
	- Interativo
		- mono ou multiusuário
	- Tempo real
3. quanto ao porte

## Estruturas do SO

- *Monolítica* - forma mais primitiva; conjunto de programas que executa sobre o hardware como se fosse um único programa; programas de usuário vistos como sub-rotinas.
- *Microkernel* - só as funções de baixo nível mais vitais; base sobre a qual o resto é construído; coleções de processos concorrentes; fornece alocação de CPU e comunicação
- *Máquina virtual* 
	- Cada VM pode ter seu próprio SO

# Processos

-  *processo* : programa em execução, estático
- um programa pode abrir *N* processos
- Cada processo possui: programa, espaço de endereço de memória e contextos de software (atributos)
- Bloco de Controle de processos (BCP)
	- identificação do processo
- *Tabela de processos*

### Estados de um processos

- *Indefinido* - Desconhecido ao SO: antes de criado e depois de destruído
- *Bloqueado* - Parado à espera de um evento
- *Pronto* - Só não executa porque a CPU está com outro processo
- *Execução* - Andamento progressivo normal, usando a CPU

## Ações de transição (6)

- *Criar* - colocar o processo na memória, tornando-o conhecido ao sistema;
- *Acordar* - liberar o andamento quando ocorre um evento: bloqueado → pronto;
- *Despachar* - retirar da fila e colocar em execução: pronto → executando;
- *Bloquear* - parar para esperar um evento: executando → bloqueado;
- *Preempção (suspender)* - parar por motivos alheios ao processo, como a comutação forçada de fatias de tempo: executando → pronto;
- *Destruir* - liberar a memória, tornando o processo desconhecido ao sistema.

## Eventos que causam a criação

- *Inicialização do sistema*
- *Chamada ao sistema de criação por um processo em execução;*
- *Requisição de usuário*
- *Início de um job em lote*

## Condições de término

- *Saída normal* (voluntária) - exit / ExitProcess;
- *Saída por erro* (voluntária) - ex.: gcc arquivo.c inexistente;
- *Erro fatal* (involuntária) — divisão por zero, memória inexistente, instrução ilegal;
- *Destruído por outro processo* (involuntária) — kill / TerminateProcess.

## Hierarquia de processos

- pai cria filho, que pode criar seus próprios processos
- *Unix* : chama isso de process group
- *Windows* não possui conceito de hierarquia - todos os processos são criados da mesma forma
- A árvore  de processos só possui no maximo 3 níveis  (pai, filho e neto)

## Chamadas de sistema

- *TRAP* : instrução que permite o acesso ao modo kernel

## Escalonamento

- o *escalonador* escolhe o processo que usará a CPU; é executado na mudança de contexto e conta com *auxílio de hardware*
- *Preemptivo x Não Preemptivo*
- **Quando escalonar**
	- um novo processo é criado
	- Um processo termina e um pronto deve executar;
	- Um processo é bloqueado (semáforo, E/S);
	- Ocorre interrupção de E/S (executar quem esperava, continuar o corrente ou executar um terceiro).

## Critérios de escalonamento

- *Justiça* - parcela justa de CPU para cada processo;
- *Balanceamento* - diminuir a ociosidade do sistema;
- *Políticas do sistema* - prioridade de processos.

- **TEMPO DE TURNAROUND**
	- Tfinal - Tchegada
	- instante final que ele acaba de ser executado - tempo que ele chegou

## Algoritmos para sistema Batch 

- **FCFS / FIFO** - Ordem de requisição; fácil de programar. Ineficiente com processos demorados
- **SJF** - menores primeiros (que ja chegaram)
- **SRTN** - Menor tempo restante possível (meio dinamico), suspende o atual se o novo for menor, meior ruim pq fica trocando de processo (**TEMPO DE CHAVEAMENTO**)

- *tempo de chaveamento (context switch)* é o tempo gasto pelo SO para salvar o estado do processo em execução e carregar o estado do próximo processo a rodar. É overhead puro — tempo em que a CPU não faz trabalho útil.

## Algoritmos para sistema Interativos

- **Round-Robin**
	- trade off do quantum
		- quantum muito pequeno - muitas trocas de contexto -> cai eficiencia da CPU
		- quantum muito longo - compromete o tempo de resposta
- **Prioridade**
- **Múltiplas filas**
- **Shortest Process Next**
- **Garantido**
- **Lottery**
- **Fair - Share**

- *Turnaround médio* = soma de todos os N turnarounds / N

# Threads

- ou processo leve, unidade básica de utilização da CPU
- formada por *contador de programa, conjunto de registradores e pilha de execução*
- **TASK** - conjunto de threads
- não roda sozinha ?
- *Processo x Threads*

## porque usar threads?

- *Razões*
	- Múltiplas atividades "ao mesmo tempo"
	- mais fácil de gerenciar
	- paralelismo real com múltiplas CPU
- *Benefícios*
	- Capacidade de resposta

##  Estados

- três estados
	-  executando
	- pronto (elegível, mas não em execução)
	- bloqueado (inelegível)

## Modelos de multithreading

- Muitos-pra-Um -> muitas de usuário para uma de kernel 
- Um-para-Um
- Muitos-para-Muitos

>>  **NAO CONFUNDIR MULTIPROGRAMAÇÃO, MULTIPROCESSAMENTO E MULTITHREADING**

# Comunicação e Deadlock

- **Condição de corrida** : dois ou mais processos leem/escrevem um dado compartilhado

- **Região crítica** :  trechos acessados por dois ou mais processos ao mesmo tempo
	- 2 processos nao podem estar na região crítica ao mesmo tempo

### Espera ocupada e suas falhas (busy waiting)

### Peterson e TSL

- nao cai na prova
### Sleep/Wakeup e o produtor/consumidor

- *Sleep* : bloqueia o processo que a chamou
- *Wakeup* : acorda um processo

### Semáforos

- *down (P)* - se o valor > 0, decrementa; cc, bloqueia o processo
- *up (V)* : incrementa; se há processos bloqueados, desbloqueia um, e nesse caso o valor *permanece o mesmo*
- *Mutex*: semáforo binário que garante exclusão mútua

### Monitores

### Passagem de mensagem

## Problemas Clássicos de IPC

- *Produtor/consumidor*
- *Leitores/Escritores*
- *Jantar dos filósofos*
- *Barbeiro sonolento*

## Deadlock 

## Estratégias de tratamento

- *Ignorar o problema*
- Detectar e recuperar
- *Evitar dinamicamente*
- *prevenir* - nao satisfazer uma das quatro condições
## Evitar - estado seguro e algoritmo do banqueiro

- *Seguro* - nao provoca deadlock
- *Inseguro* - PODE provocar deadlock

- **Algoritmo do banqueiro**
	- Análise de toda requisição de recursos que chega, se leva a estado seguro, atende; cc, adia
	- Na teoria é OTIMO