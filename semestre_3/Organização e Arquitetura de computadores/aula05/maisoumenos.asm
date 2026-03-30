	.data
	.align 0 #alinha para byte
str1:	.asciz "Hello World++!"
str2:	.asciz "Hello World--!"
	
	.text
	.align 2 #alinhar para 32 bits, cada instrução tem 32 bits
	.globl main

main:	addi a7,zero,5 #codigo para ler word
	ecall #le e seta em a0
	add s0,a0,zero #salvamos a0 em s0 (conteúdo lido)
	blt s0, zero, print_neg #se s0 for menor que zero, vai pra print_neg
	addi a7,zero,4
	la a0, str1
	ecall
	j the_end

print_neg:
	addi a7,zero,4
	la a0,str2
	ecall

the_end:
	addi a7, zero, 1
	add a0,zero,s0
	ecall
	li a7,10 #addi a7,zero,10
	ecall
	