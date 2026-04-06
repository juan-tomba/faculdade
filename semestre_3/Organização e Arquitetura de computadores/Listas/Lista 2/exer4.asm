	.data
	.align 0
str:	.asciz "\n"
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 5
	ecall
	add s0, zero, a0
	addi t0, zero, 2
	mul s1, s0, t0
	addi a7, zero, 1
	add a0, s1, zero
	ecall
	addi t0, t0, 1
	mul s2, s0, t0
	addi a7, zero, 4
	la a0, str
	ecall
	addi a7, zero, 1
	add a0, s2, zero
	ecall
	addi a7, zero, 10
	ecall
	