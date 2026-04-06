## Arquitetura CISC

- **CISC – Complex Instruction Set Computer**
- **CISC tenta reduzir o número de instruções por programa**, fazendo instruções mais poderosas.
- Computadores complexos devido a:
	- Instruções complexas que demandam um número grande de ciclos para serem executadas
	- Diversos modos de endereçamento
	- Instruções sem tamanho fixo
- Questionamentos acerca da necessidade de certas instruções
- Nas arquiteturas CISC fica mais difícil implementar o pipeline
- A taxa média de execução das instruções por ciclo tende a ser bem menor do que 1 IPC (instruction per cycle)
- Instrução complexa significa um maior tempo para decodificar e executar, muitas das quais são raramente usadas
- **Então, surgiu a arquitetura RISC**
- Assembly intel - cisc
	- Mas arquitetura intel - risc (quebra o cisc em risc)

- **EXEMPLO**
```
ADD [A], [B]
```

## Arquitetura RISC

- **RISC – Reduced Instruction Set Computer**
- Instruções mais simples, demandando um número fixo de ciclos de máquinas para sua execução
	- As instruções são executadas na sua maioria em apenas um ciclo de máquina
- Uso de poucos e simples modos de endereçamento
- Apenas instruções de load/store referenciam operandos na memória principal
- Cada fase de processamento da instrução tem a duração fixa igual a um ciclo de máquina
- Formato fixo das instruções facilita o pipeline
- **Apenas instruções load/store acessam memória**
- **EXEMPLO

```
lw t0, 0(t1)
lw t2, 4(t1)
add t3, t0, t2
```

- **Primeiros computadores RISC:**
	- IBM 801 (1980)
	- Berkeley RISC I e RISC II (1980 e 1981)
	- Stanford MIPS (1981)

## RISC-V (RISC-five)

- Arquitetura de conjunto de instruções universal
	- Arquitetura aberta
- Atender todos os tamanhos de processadores
- Funcionar bem em uma grande variedade de software e ling. de programação
- Ser eficiente para todo tipo de microarquitetura (organização)
- Mantida atualmente pela Fundação RISC-V
- Características da Arquitetura RISC-V:
	- Arquitetura de 32 bits (existem arquiteturas mais recentes de 64 bits)
	- Possui 32 registradores de propósito geral 
	- Possui 32 registradores para ponto flutuante
- Menor memória endereçável é 1 byte
- Tipos de dados:
	- halfword: 2 bytes 
	- word: 4 bytes 
	- float: 4 bytes 
	- double: 8 bytes

- **Arquitetura Load/Store**: Os valores têm que ser carregados nos registradores antes de realizar as operações.
	- Não há instruções que operam diretamente em valores na memória!

![[Pasted image 20260311135934.png]]

| registrador | função               |
| ----------- | -------------------- |
| x0 (zero)   | sempre 0             |
| ra          | return address       |
| sp          | stack pointer        |
| a0–a7       | argumentos / retorno |
| t0–t6       | temporários          |
| s0–s11      | registradores salvos |
## Assembly RISC-V

- **Estrutura do código**
	- Rótulos e diretivas
	- Chamada ao sistema para E/S - ecall
- Não é obrigatório identar, mas é essencial

### Estrutura de um programa em assembly

- Segmento de texto (código)
	- endereço 0x00010000
- Segmento de dados
	- endereço 0x10000000

- .data
	- diretiva que indica o início do segmento de dados
	- logo após declarar variáveis estáticas
- .text
	- diretiva que indica o início do segmento de texto
	- logo após: código fonte

|segmento|função|
|---|---|
|.text|código|
|.data|variáveis|
|heap|memória dinâmica|
|stack|pilha|

- layout de memória usado pelo RISC-V:
![[Pasted image 20260316110921.png]]

### Rótulos

- Identificam uma linha no código para referência
- Útil para:
	- desvios condicionais (estruturas condicionais e repetição)
	- desvios incondicionais
	- chamadas a procedimento
		- uma variação de desvio incondicional

### Exemplos

![[Pasted image 20260316112222.png]]

- Hello world em código:
```
		.data
string: .asciz "Hello World"

		.text
		.globl main
		
main:   addi a7, zero, 4 #atribui 4 ao a7
		#li a7, 4
		la a0, string     #la - load adress
		
		ecall
		
		addi a7, 10
		ecall
```

- Imprimir 2 strings:

```
	.data
str1: .asciz "Hello "
str2: .asciz "World"

	.text
	.globl main

main:

	li a7, 4
	la a0, str1
	ecall
	
	li a7, 4
	la a0, str2
	ecall
	
	li a7, 10
	ecall
```

- Loop:
```c
//Assembly
beq t0, t1, fim_loop
#codigo interno ao loop
j loop
#primeira instrução fora do loop
```

- Loop em assembly é análogo ao do-while
- Agora em C, usando o do while:
```C
do{
//codigo interno do loop
} 
while(bne t0,t1,loop)
```


### Montador/ecall

![[Pasted image 20260316112335.png]]


- **ecall**: é uma instrução utilizada para solicitar um serviço ao sistema operacional (SO) ou ao ambiente de execução (como um simulador)

![[Pasted image 20260316112655.png]]

- MUITO IMPORTANTE: **no simulador RARS** o registrador **a7 indica qual serviço do sistema você quer usar**. (por isso no hello world coloca 4 em a7, é pra printar string, como mostra a tavela)

![[Pasted image 20260316112724.png]]

| Tipo                   | Exemplo             | Formato geral                  | Descrição                                | Exemplo explicado               |
| ---------------------- | ------------------- | ------------------------------ | ---------------------------------------- | ------------------------------- |
| R-type                 | `add t0, t1, t2`    | `rd = rs1 op rs2`              | Operações entre registradores            | `t0 = t1 + t2`                  |
| I-type                 | `addi t0, t1, 5`    | `rd = rs1 op imediato`         | Usa um valor constante (immediate)       | `t0 = t1 + 5`                   |
| Load                   | `lw t0, 0(t1)`      | `rd = Mem[rs1 + offset]`       | Carrega dado da memória para registrador | `t0 = memória[t1 + 0]`          |
| Store                  | `sw t0, 0(t1)`      | `Mem[rs1 + offset] = rs2`      | Guarda dado do registrador na memória    | `memória[t1 + 0] = t0`          |
| Branch                 | `beq t0, t1, label` | `if (rs1 cond rs2) goto label` | Desvio condicional                       | se `t0 == t1` pula para `label` |
| Jump                   | `j label`           | `goto label`                   | Desvio incondicional                     | pula direto para `label`        |
| Jump and Link          | `jal label`         | `ra = PC+4 ; goto label`       | Salta para função e salva retorno        | usado em chamadas de função     |
| Jump and Link Register | `jalr ra`           | `goto endereço em registrador` | Retorno de função                        | volta para quem chamou          |




- **Fatos curiosos**
	- bne - verifica se duas variáveis são diferentes
	- j = jump
	- utilizar RARS 1.5
	- arquivo: riscv1.asm

> [!question]- Por que **a7** define o `ecall`?
> - Porque a **convenção de chamada do RISC-V (ABI)** definiu que o **número da syscall fica no registrador `a7`**.

>Pense no `ecall` como se fosse uma **função do sistema operacional**:
>	syscall(numero, arg1, arg2, arg3...)
>em que:
>numero → a7  
arg1 → a0  
arg2 → a1  
arg3 → a2



