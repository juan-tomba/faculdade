## Definição Sistema Operacional

-  **Software responsável por gerenciar dispositivos que
compõem um sistema computacional e realizar a interação
entre o usuário e esses dispositivos**

## Sistema Operacional x Programas do Sistema

-  *SO* - Roda em modo kernel ou supervisor, o programa tem acesso ao hardware
-  *Programas do sistema ou da aplicação* - rodam em modo usuário
	-  tem acesso a determinadas regiões de memória
	-  precisam pedir para o SO para tarefas específicas

## Serviços oferecidos pelo SO

-  Facilidade para criação de programas
-  Execução de programas
-  Acesso controlado a arquivos
-  Acesso ao sistema
-  Detecção de erros

# Sistemas Computacionais

- Consiste de:
	- Um ou mais processadores
	- Memória principal
	- Discos, impressoras, teclado, monitor, interfaces de redes e outros dispositivos de E/S

-  *Sistemas sem SO*
	-  Gasto maior no tempo de programação
	-  Aumento da dificuldade
	-  Usuário preocupado com detalhes do hardware
-  *Sistemas com SO*
	-  Maior racionalidade
	-  Maior portabilidade
	-  Maior dedicação a problemas de alto nível

-  *Analogias para o SO*
	-  É um **fiscal** que controla os usuários
	-  É um **juiz** que aloca corretamente os recursos ao hardware
	-  **Ilusionista** - fornece abstrações limpas e fáceis de usar recursos físicos
		- memória infinita
		- limitações de mascaramento, virtualização
		-  objetos de nível superior: arquivos, usuários, mensagens

## O que é um processo?

-  *Um programa em execução*
-  De que consiste um processo?
	-  Espaço de endereço
	-  Uma ou mais thread de controle de execução naquele espaço de endereço

## Exemplo

Como **Máquina Estendida**
-  Como é feita a E/S de um disco
	-  SO : Baixo nível
		-  Número de parâmetros
		- Endereço do bloco a ser lido
		-  Número de setores por trilha
		-  Modo de gravação
	-  Usuário : Alto nível
		-  Visualização do arquivo a ser lido/escrito
		-  Arquivo é lido e escrito
		-  Arquivo é fechado

-  Como **Gerenciador de recursos/cola**
	-  Gerencias os recursos e dispositivos do computador
	-  Se dois dispositivos querem utilizar o mesmo recurso, o SO define a ordem para que ambos consigam acesso
	-  Uso do HD e memória

# Tipos de SO
## Classificação quanto ao *compartilhamento de hardware*

- **Sistemas Operacionais Monoprogramados ou Monotarefa**
	- Só permite um programa ativo em um dado período de tempo, o qual permanece em sua memória até seu término
	- Se caracterizam por permitir que o processador, a memória e os periféricos permaneçam exclusivamente dedicados a execução de um único programa. Recursos são mal utilizados, entretanto, é fácil de ser implementado.
	- Ex: DOS
-  **Sistemas Operacionais Multiprogramados ou Multitarefa** 
	-  Mantém mais que um programa simultaneamente na memória principal, para permitir o compartilhamento efetivo de tempo de CPU e demais recursos
	- Neste S.O. vários programas dividem os recursos do sistema. As vantagens do uso destes sistemas são o aumento da produtividade dos seus usuários e a redução de custos a partir do compartilhamento dos diversos recursos do sistema.
	- Ex: Windows NT, UNIX

## Classificação quanto a *Interação permitida*

- **SO para processamento em Batch (lote)**
	- Jobs dos usuários são submetidos em ordem sequencial para a execução 
	- Não existe interação entre usuários e o job durante a execução.

-  **SO interativo**
	- O sistema permite que os usuários interajam com suas computações na forma de diálogo 
	- Podem ser projetados como sistemas mono-usuários ou multiusuários (usando conceitos de multiprogramação e time-sharing)

-  **SO de tempo real**
	- Usados para servir aplicações que atendem processos externos, e que possuem tempo de resposta limitados
	- Geralmente sinais de interrupções comandam a atenção do sistema
	- Geralmente são projetados para uma aplicação específica

## Classificação quanto ao *Porte*

- S.O. de Computadores de Grande Porte 
- S.O. de Servidores 
- S.O. de Multiprocessadores 
- S.O. de Computadores Pessoais 
- S.O. de Tempo Real 
- S.O. de Embarcados 
- S.O. de Cartões Inteligentes

## Estrutura do SO
### Estrutura Monolítica

### Estrutura do MicroKernel

### Monolítica x MicroKernel

### Máquina Virtual (VM)

-  Virtual Machine (VM)
-  Cada VM é independente das demais, é possível que tenha seu próprio SO
- Este nível  cria diversas máquinas virtuais independentes
