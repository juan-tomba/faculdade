	.data
	.align 0
resul:	.asciz "\nO maior é: "
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 5
	ecall
	add s0, a0, zero
	addi a7, zero, 5
	ecall
	add s1, a0, zero
	bge s0, s1, primeiro
	addi a7, zero, 4
	la a0, resul
	ecall
	addi a7, zero, 1
	addi a0, s1, 0
	ecall
	j sair

primeiro:
	addi a7, zero, 4
	la a0, resul
	ecall
	addi a7, zero, 1
	addi a0, s0, 0
	ecall
sair:
	addi a7, zero, 10
	ecall