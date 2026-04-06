	.data
	.align 0
linha:	.asciz "\n"
	.text
	.align 2
	.globl main
main:
	addi a7, zero, 5
	ecall
	add s0, a0, zero
	addi t0, zero, 0
loop:
	addi t0, t0, 1 #vai até N
	addi a7, zero, 1
	add a0, t0, zero
	ecall
	addi a7, zero, 4
	la a0, linha
	ecall
	bne s0, t0, loop
	addi a7, zero, 10
	ecall
	