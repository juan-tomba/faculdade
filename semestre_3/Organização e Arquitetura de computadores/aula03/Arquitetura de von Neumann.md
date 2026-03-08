- A arquitetura proposta por von Neumann é composta por componentes lógicos básicos + programação

![[Pasted image 20260303131539.png]]

- Três pontos importantes:
	- Dados e instruções são representados na memória
	- A memória é endereçada pela posição e não pelo conteúdo;
	- A execução das instruções é considerada sequencial

## Hardware de propósito geral

- Sequência de passos, em que cada passo faz uma operação aritmética ou lógica
- Cada operação requer sinais de controle diferentes

## Função da Unidade de Controle

- Interpretar o código e gerar os sinais de controle que executarão a instrução requerida
- Para cada operação, **Um código único é fornecido**
	- Ex: ADD, MOVE, .....

## Componentes

- CPU (Unidade de Controle + Unidade Lógica e Aritmética)
	- UC + Caminho de Dados (barramento interno + unidades funcionais)
- Entrada/Saída (E/S)
	- Inserir dados/instruções para o computador
	- Enviar resultados para fora do computador
- Memória Principal
	- Fornecer instruções e operandos para execução
	- Armazenar resultados fora da CPU

## Componentes do Computador

![[Pasted image 20260304131752.png]]

- Funcionamento dos componentes: [[Evolução e questões de desempenho]]

## Ciclo de instrução

![[Pasted image 20260304132237.png]]


### Ciclo de busca (fetch)

- No contador de programas (PC) estará o endereço da próxima instrução
- O processador faz a busca da instrução na posição de memória que está armazenada no PC
	- MAR = PC
	- MBR = memória(MAR)
- PC = PC + 1
	- A menos que a próxima instrução não esteja armazenada na posição seguinte (instruções de desvio)
- A instrução é armazenada no registrador de instrução (IR)
	- IR = MBR

### Ciclo de execução

- UC decodifica a instrução e determina quais ações são necessárias
- A execução da instrução se resume em:
	- **Processador-Memória**: transferência de dados do processador para a memória ou da memória para o processador
	- **Processador-E/S**: transferência de dados entre o processador e um dispositivo de E/S
	- **Processamento de dados**: execução de operações aritméticas ou lógicas sobre os dados
	- **Controle**: especifica que a sequência de execução de instruções seja alterada
	- **Combinação das 4 possibilidades**

# Máquina Hipotética

## Características de uma máquina hipotética

- Registradores:
	- **Contador de programa (PC)** = endereço da próxima instrução
	- **Registrador de instrução (IR)** = instrução que está sendo executada
	- **Acumulador (AC)** = armazenamento temporário de dados
- Códigos de operações:
	- 0001 = carregar AC a partir do endereço de memória especificado
		- (AC) <- (mem)
	- 0010 = armazenar o valor contido em AC no endereço de memória especificado
		- (mem) <- (AC)
	- 0101 = acrescentar ao valor contido em AC o valor contido no endereço de memória especificado
		- (AC) <- (AC) +(mem)

## Exemplo de execução de um programa

![[Pasted image 20260304135713.png]]


- 1° dígito = opcode
- resto = endereço

- **EXEMPLO DA IMAGEM**
- 1940 = (AC) <- mem(940)
	- AC = 3
- 5941 = (AC) <- (AC) + mem(941)
	- AC = 5
- 2941 = mem(941) <- AC
	- endereço 941: 0005