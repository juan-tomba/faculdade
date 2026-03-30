	.data #strcpy
	.align 0
str_src: .asciz "Teste"
str_dst: .space 6 #reservo 6 bytes na memória estática
	
	.text
	.align 2
	.globl main

main:	# t0 = endereço str_src
	la t0, str_src
	# t1 = endereço str_dst
	la t1, str_dst

loop_copy:
	lb s0,0(t0) #le a posição apontada por t0 em s0
	sb s0,0(t1) #escreve s0 na posição apontada por t1
	addi t0,t0,1 #avança na string
	addi t1,t1,1
	bne s0,zero,loop_copy #compara o caracter lido com zero
	# imprime str_dst
	addi a7, zero, 4
	la a0, str_dst
	ecall
	addi a7, zero, 10
	ecall