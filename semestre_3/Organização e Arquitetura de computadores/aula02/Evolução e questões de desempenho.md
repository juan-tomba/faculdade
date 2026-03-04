## Computadores digitais

Convenção:
- Voltagem alta: valores logicamente verdadeiros, ou 1
- Voltagem baixa: valores logicamente negativos, ou 0

### Funcionamento da CPU/Ram 

(Desenhos no caderno)

- **Memory Adress Register (MAR)** - guarda **o endereço da memória** que a CPU quer acessar (para ler ou escrever dados).
- **Memory Buffer Register (MBR)** - guarda **o endereço da próxima instrução** que a CPU vai executar.
- **Program Counter (PC)** - sempre tem o endereço da próxima instrução
- **Instruction Register (IR)** - contém **a instrução atual que está sendo executada pela CPU**.
- **Unidade de controle (UC)** - **coordena e controla** a execução das instruções, enviando sinais para os outros componentes da CPU.

### Arquiteturas de processador

**RISC (Reduced Instruction Set Computer)**
- Usa **conjunto pequeno e simples de instruções**.
- Cada instrução geralmente executa em **1 ciclo de clock**.
- Foca em **simplicidade e alta eficiência**.
- Muito usado em **processadores modernos e dispositivos móveis** (ex: ARM).

**CISC (Complex Instruction Set Computer)**
- Possui **grande conjunto de instruções complexas**.
- Algumas instruções podem executar **várias operações de uma vez**.
- Pode precisar de **mais ciclos de clock por instrução**.
- Exemplo clássico: **processadores x86 da Intel/AMD**.

# Evolução dos computadores

## 1° Geração - ENIAC

**Electronic Numerical Integrator And Computer**

- Primeiro Computador digital eletrônico de grande escala
- Usado até 1955
- Laboratório de pesquisas balísticas do exército americano
- Programado manualmente por chaves (switches)

### von Neumann/Turing

- **Conceito de Programa Armazenado - 1945**
	- Código e dados dos programas ficam armazenados na memória
![[Pasted image 20260228160759.png]]
## 2° Geração - Transistores

- Inventado em 1947
- Marcam o início da 2° geração de máquinas
- Linguagens de programação de alto nível
- Software de sistema

Código em C -> compilador -> Assembly -> Assembler -> Linguagem de máquina (binário)

## 3° Geração

- Criada a 1ª família de computadores
	- E/S
- **Introduziu o conceito de multiprogramação**
	- vários programas ao mesmo tempo na memória
- 1° minicomputador - 1964
- Estrutura de barramento

### 4° Geração

- 1° microprocessador - 1971 - 4004
	- Palavra de 4 bits
- 1972 - 8008
	- Palavras de 8 bits
	- Assim como o 4040, específico para algumas aplicações
- 1974 - 8080
	- 1º microprocessador de propósito geral da Intel

### 5° Geração

- 1981 - governo Japonês planeja nova geração 
	- Baseada em IA.
	- Fracasso
- A revolução foi outra: silenciosa
	- 1989: 1° tablet sensível ao toque
- Começo de fabricação de **componentes pequenos e potentes**

## Lei de Moore

- Lei proposta por Gordon Moore – co-fundador da Intel
- **Número de transistores no chip dobrará a cada 18-24 meses**
- "Os computadores menores são mais flexíveis"

### Projeto de Computadores e Desempenho

- A demanda e as organizações atuais requerem fluxo de execução de instruções constante
- São empregadas:
	- inserção de pipelines nos processadores
	- caches L1 & L2 on board

### Balanço do desempenho

- Capacidade da memória aumentou muito
- Velocidade do processador aumentou muito
- Velocidade no acesso à memória cresceu menos que a velocidade do processador
	- Pode gerar gargalo no desempenho

### Soluções para o desempenho da RAM

- Aumentar nº de bits recebidos por acesso
	- Tornar DRAM + “larga” em vez de aumentar capacidade
	- Implica em mudar barramentos
- Reduzir frequência de acessos à memória
	- usar estrutura de caches + complexas, tanto na DRAM quanto no processador
- Aumentar a largura de banda dos barramentos
	- Mais velozes

### Resumo

- Evolução dos computadores foi marcada por:
	- maior velocidade dos processadores 
	- diminuição do tamanho dos componentes 
	- maior capacidade (densidade) das memórias
	- maior capacidade e velocidade de E/S
- Velocidades maiores vêm da diminuição do tamanho
	- menores distâncias entre os componentes 
	- ganhos reais de desempenho vêm de mudanças na organização 
		- pipeline, execução paralela, especulativa e predição de desvios
- Balanceamento no desempenho dos componentes
	- Ex.: ganhos na velocidade do processador podem ser prejudicados por atrasos devido à velocidade da memória 
	- possíveis soluções: cache, barramentos mais largos, entre outras
