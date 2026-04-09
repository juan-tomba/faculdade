	.data
	.align 0
str:	.asciz	"\n"
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 5
	ecall
	add s0, zero, a0
	add t0, zero, s0
	addi s1, zero, 1
loop:
	addi a7, zero, 1
	add a0, zero, t0
	ecall
	addi t0, t0, -1
	addi a7, zero, 4
	la a0, str
	ecall
	bge  t0, s1, loop
	addi a7, zero, 10
	ecall
	