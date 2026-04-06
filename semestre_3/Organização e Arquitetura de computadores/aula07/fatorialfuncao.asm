	.data
	.align 0
str_oi:	.asciz "Digite um numero maior ou igual a 0: "
str_resul:	.asciz "O fatorial de "
str_resul2:	.asciz " e "
str_erro:	.asciz "Entrada invalida\n"
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
	# verificar se a0 e maior que 0
	bge a0, zero, continua
	addi a7, zero, 4
	la a0, str_erro
	ecall 
	j loop_leitura
continua:	# chamada func fatorial
	#salvar o valor lido em s0
	add s0, zero, a0
	jal fatorial
	addi a7, zero, 4 #impressao string
	la a0, str_resul
	ecall
	addi a7, zero, 1 # impress�o numero digitado pelo usuario
	add a0, zero, s0
	ecall
	#impress�o str_resul2
	addi a7, zero, 4
	la a0, str_resul2
	ecall
	addi a7, zero, 1 # impress�o fatorial calculado
	add a0, zero, a1
	ecall
	addi a7, zero, 10
	ecall
fatorial: #fun��o para calcular o fatorial do n�mero digitado
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
	
