	.data
	.align 0
eh_par:	.asciz "\nÉ par"
eh_impar:	.asciz "\nÉ impar"
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 5
	ecall
	add s0, a0, zero
	addi t0, zero, 2
	rem t1, s0, t0 # mod e armazena em t1
	addi t2, zero, 0
	beq t1, t2, par
	addi a7, zero, 4
	la a0, eh_impar
	ecall
	j sair
par:
	addi a7, zero, 4
	la a0, eh_par
	ecall
sair:
	addi a7, zero, 10
	ecall
	