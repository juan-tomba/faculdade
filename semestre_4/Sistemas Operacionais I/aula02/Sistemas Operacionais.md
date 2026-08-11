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

# Sistemas Operacionais

-  *Sistemas sem SO*
	-  Gasto maior no tempo de programação
	-  Aumento da dificuldade
	-  Usuário preocupado com detalhes do hardware
-  *Sistemas com SO*
	-  Maior racionalidade
	-  Maior portabilidade
	-  Maior dedicação a problemas de alto nível

-  *Analogias*
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
-  Como é feita a E/S de  um disco
	-  SO : Baixo nível
		-  Número de parametros
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

## Classificação quanto ao *compartilhamento de hardware*

- **Sistemas Operacionais Monoprogramados**
	- Só permite um programa ativo em um dado período de tempo, o qual permanece em sua memória até seu término
	- Ex: DOS
-  **Sistemas Operacionais Multiprogramados**
	-  Mantém mais que um programa simultaneamente na memória principal, para permitir o compartilhamento efetivo de tempo de CPU e demais recursos
	- Ex: Windows NT, UNIX

## Classificação quanto a *Interação permitida*

-  **SO interativo**

-  **SO de tempo real**

## Classificação quanto ao *Porte*

## Estrutura do SO

