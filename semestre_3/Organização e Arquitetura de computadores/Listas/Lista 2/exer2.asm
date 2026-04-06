	.data
	.align 0
str:	.asciz "Digite um numero: "
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 4
	la a0, str
	ecall
	addi a7, zero, 5
	ecall
	addi a7, zero, 1
	ecall
	addi a7, zero, 10
	ecall