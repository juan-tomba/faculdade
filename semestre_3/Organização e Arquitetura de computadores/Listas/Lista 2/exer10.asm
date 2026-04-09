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
	addi t0, zero, 1 #itera até N
	addi t1, zero, 0 #acumulador
loop:
	add t1, t1, t0
	addi t0, t0, 1
	blt t0, s0, loop
	addi a7, zero, 1
	addi a0, t1, 0
	ecall
	addi a7, zero, 10
	ecall