-  É um processo em execução, incluindo os valores correntes, registradores, variáveis
-  *Processo é dinamico, programa é estático*
- Nem sempre um programa equivale a apenas um processo
- Em sistemas que permitem **reentrancia** o código de um programa pode gerar vários processos

## Reentrancia

## Bloco de controle de Processo (BCP)

- Contém informações sobre o processo
-  É uma estrutura de dados contendo informações importantes sobre o processo
	- Identificação do processo
	- estado do processo
	- prioridade do processo
	- ponteiros para a localização do processo na memória ou disco
	- contador de programa

## Tabela de processos

## Processo - criação

-  Principais eventos que causam a criação de um processo
	- Inicialização do Sistema
	- Execução de uma chamada ao sistema de criação de processo por um processo em execução
	- Uma requisição de usuário para a criação de um novo processo
	- Início de um job em lote

- *Unix*
	- **FORK**
		- cria processo pai e filho com mesmo endereçamento
		- depois o processo filho tem endereçamento separado

- *Windows*
	- **CreateProcess**
		- cria processo pai e filho com mesmo endereçamento SEMPRE


## Chamada de sistema

**Até slide 28**