	.data
	.align 0
str:	.asciz "Digite um numero: "
str2:	.asciz "Digite outro numero: "
str3:	.asciz "\nA soma é: "
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 4
	la a0, str
	ecall
	addi a7, zero, 5
	ecall
	add t0, a0, zero
	addi a7, zero, 4
	la a0, str2
	ecall
	addi a7, zero, 5
	ecall
	add t1, t0, a0
	addi a7, zero, 4
	la a0, str3
	ecall
	addi a7, zero, 1
	addi a0, t1, 0
	ecall
	addi a7, zero, 10
	ecall