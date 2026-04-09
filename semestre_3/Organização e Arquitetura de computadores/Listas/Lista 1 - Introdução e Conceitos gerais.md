### **1. Com suas próprias palavras, diferencie Organização de Arquitetura de Computadores.**

-  Arquitetura é o conjunto de atributos visíveis ao programador (conjunto de instruções, número de bits usados para representar dados, etc...). Já Organização se refere a como esses atributos são implementados (interface, tecnologia de memória, etc)
### **2. Qual a importância de se estudar Organização e Arquitetura?**

- O estudo é realizado para a compreensão (como programadores) de como funciona o sistema de processamento de instruções e registradores, garantindo conhecimento sobre os comandos que nosso programa tem sobre o computador.

### **3. Quais os principais componentes de um computador? Liste e detalhe a função deles**
 
- CPU - Executa instruções e processa dados
- Memória Principal - Armazena temporiamente os dados/instruções do programa
- Módulo de E/S - Recebe entrada do usuário e Imprime saída para o usuário
- Sistema de barramento - permite e interconexão entre os elementos

### **4. Quais os principais componentes da CPU? Liste e detalhe a função deles.**
 
- Program Counter (PC) - Armazena o endereço da próxima instrução
- Instruction Register (IR) -Contém a atual instrução da CPU
- Memory Buffer Register (MBR) - Guarda dados que vêm da memória ou vão para ela
- Memory Adress Register (MAR) - Armazena o endereço físico da memória RAM que será lida/escrita
-  Unidade de Controle (UC) - Controla as instruções e envia sinais para os outros componentes 
- Acumulador(AC) - Serve armazenar temporiamente os dados
- Unidade Lógica e Aritmética (ULA) - Realiza cálculos matemáticos (soma, subtração) e operações lógicas (AND, OR, NOT).

### **5. Defina com suas próprias palavras o conceito de Programa Armazenado proposto por von Neumann.**

- O código e os dados do programa são armazenados na memória principal (RAM) durante a execução

###  **6. O que caracteriza uma arquitetura de propósito geral?**

- É capaz de executar diferentes tipos de programas, não sendo especializada para uma única tarefa.

### **7. Defina com suas palavras qual a função dos sinais de controle.**

- Sinais de controle servem para coordenar as instruções na CPU

### **8. Como a Unidade de Controle comanda todos os componentes do computador?**
- Ela interpreta as instruções fornecidas e gera os sinais de controle para ativar os componentes da CPU

### **9. Defina o ciclo de instrução e suas fases**

- São duas fases:
	- Ciclo de busca: O processador busca o endereço da instrução armazenada em PC. Após isso incrementa o PC (PC = PC + 1), exceto em instruções de desvio. Por fim, a instrução é armazenada em IR.
		- MAR = PC
		- MBR = memoria(MAR)
		- PC = PC + 1
		- IR = MBR
	- Ciclo de execução: A UC decodifica a instrução e determina as ações necessárias (sinais de controle).

### **10. Dada a organização hipotética estudada na aula, explique a função dos registradores PC, MAR, MBR e IR.**

- Program Counter (PC) - Armazena o endereço da próxima instrução
- Instruction Register (IR) - Contém a atual instrução da CPU
- Memory Buffer Register (MBR) -  Guarda dados que vêm da memória ou vão para ela
- Memory Adress Register (MAR) - Armazena o endereço físico da memória RAM que será lida/escrita

### **11.**

- a) O código dobra um valor x, e divide por 2 outro valor y

- b)

| **Ciclo** | **PC** | **RAM[830]** | **RAM[832]** | **IR** | **AC** | **Operação / Observação**              |
| --------- | ------ | ------------ | ------------ | ------ | ------ | -------------------------------------- |
| 1         | 302    | 20           | 800          | 1830   | XXXX   | Busca da Instr. 1 (load 830)           |
| 2         | 302    | 20           | 800          | 1830   | 20     | Execução: AC recebe 20h                |
| 3         | 304    | 20           | 800          | 6000   | 20     | Busca da Instr. 2 (shiftl)             |
| 4         | 304    | 20           | 800          | 6000   | 40     | Execução: AC desloca p/ esquerda (40h) |
| 5         | 306    | 20           | 800          | 2830   | 40     | Busca da Instr. 3 (store 830)          |
| 6         | 306    | 40           | 800          | 2830   | 40     | Execução: RAM[830] recebe 40h          |
| 7         | 308    | 40           | 800          | 1832   | 40     | Busca da Instr. 4 (load 832)           |
| 8         | 308    | 40           | 800          | 1832   | 800    | Execução: AC recebe 800h               |
| 9         | 30a    | 40           | 800          | 7000   | 800    | Busca da Instr. 5 (shiftr)             |
| 10        | 30a    | 40           | 800          | 7000   | 400    | Execução: AC desloca p/ direita (400h) |
| 11        | 30c    | 40           | 800          | 2832   | 400    | Busca da Instr. 6 (store 832)          |
| 12        | 30c    | 40           | 400          | 2832   | 400    | Execução: RAM[832] recebe 400h         |

