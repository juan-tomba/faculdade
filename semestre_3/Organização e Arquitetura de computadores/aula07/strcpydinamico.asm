	.data
	.align 0
str_src:	.asciz "Teste1"
	.align 2
p_str_dst:	.word #variavel ponteiro
	.text
	.align 2
	.globl main

main: 	#calcular o tamanho da string
	la t0, str_src #armazenar endereço em t0 de str_src
	addi t3, zero, 0 #variável contadora
loop:	lb s0, 0(t0) # pega o connteúdo de (t0 + 0) e coloca em s0
	addi t0,t0,1 # incrementa a string
	addi t3,t3,1 # incrementa a variavel contadora
	bne s0, zero, loop # compara o caracter atual em s0 (da string) com zero
	# alocação na heap de t3 bytes
	# a7 = 9, a0 = qntdade de bytes a ser alocado
	addi a7, zero, 9 # aloca memória na heap
	add a0, zero, t3
	ecall
	#salva o a0 em p_str_src
	la t1, p_str_dst
	sw a0, 0(t1)
	# cópia
	#t0 = end str_src
	#t2 = end string destino
	la t0, str_src
	la t2, p_str_dst
	lw t2, 0(t1)
loop2:	lb s0, 0(t0)
	sb s0,0(t2)
	addi t0,t0,1
	addi t2,t2,1
	bne s0, zero, loop2
	#imprimir
	addi a7, zero, 4
	la t1, p_str_dst
	lw a0, 0(t1)
	ecall
	addi a7, zero, 10
	ecall
	
	
	
	