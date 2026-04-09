	.data
	.text
	.align 2
	.globl main
main:	#ler o numero
	addi a7, zero, 5
	ecall
	#salvar em s0
	add s0, zero, a0
	#chamar func�o
	jal fatorial
	#imprimir resultado
	addi a7, zero, 1 #end1
	add a0, zero, a1
	ecall
	addi a7, zero, 10
	ecall
fatorial:
	#empilhar ra e a0
	addi sp, sp, -8
	sw ra, 0(sp)
	sw a0, 4(sp)
	beq a0, zero, retorna1	#condi��o de parada
	# decrementa o parametro e chama a fun��o novamente
	addi a0, a0, -1
	jal fatorial
	addi a0,a0,1	#end2
	mul a1, a1, a0
	j retornafat
	
	
retorna1:	#a1 = 1
	addi a1,zero,1
	#desempilhar
retornafat:	
	lw ra, 0(sp)
	lw a0, 4(sp)
	addi sp, sp, 8
	jr ra
	
