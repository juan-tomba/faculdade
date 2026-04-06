	.data
	.align 0
str:	.asciz "Boas vindas!"
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 4
	la a0, str
	ecall
	addi a7, zero, 10
	ecall
	