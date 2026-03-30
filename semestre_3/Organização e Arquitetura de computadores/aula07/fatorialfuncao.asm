	.data
	.align 0
str_oi:	.asciz "Digite um número maior ou igual a 0: "
str_resul:	.asciz "O fatorial de "
str_resul2:	.asciz " é "
str_erro:	.asciz "Entrada inválida\n"
	.text
	.align 2
	.globl main
main:	#imprimir string
loop_leitura:	addi a7, zero, 4
	la a0, str_oi
	ecall
	#ler um numero inteiro
	addi a7, zero, 5
	ecall
	# verificar se a0 é maior que 0
	bge a0, zero, continua
	addi a7, zero, 4
	la a0, str_erro
	ecall 
	j loop_leitura
continua:	# chamada func fatorial
	#salvar o valor lido em s0
	add s0, zero, a0
	jal fatorial
	addi a7, zero, 4 #impressão string
	la a0, str_resul
	ecall
	addi a7, zero, 1 # impressão numero digitado pelo usuario
	add a0, zero, s0
	ecall
	#impressão str_resul2
	addi a7, zero, 4
	la a0, str_resul2
	ecall
	addi a7, zero, 1 # impressão fatorial calculado
	add a0, zero, a1
	ecall
	addi a7, zero, 10
	ecall
fatorial: #função para calcular o fatorial do número digitado
	# parametro a0 = numero digitado
	# retorno a1
	# t0 = contador
	add t0, zero, a0
	addi a1, zero, 1
loop_fat:	
	beq t0, zero, sai
	mul a1, a1, t0
	addi t0,t0,-1
	j loop_fat
sai:
	jr ra
	