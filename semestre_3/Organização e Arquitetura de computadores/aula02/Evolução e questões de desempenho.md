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
- **Introduziu o conceito de multiprogramação**
	- vários programas ao mesmo tempo na memória