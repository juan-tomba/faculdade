	.data
	.align 0
primo:	.asciz "é primo"
nao:	.asciz "Não é primo"
	.text
	.globl main
main:
	addi a7, zero, 5
	ecall
	add s0, zero, a0
	addi t0, zero, 2 #vai até n-1
	addi t2, zero, 0
loop:
	rem t1, s0, t0
	beq t1, t2, nao_eh
	addi t0, t0, 1
	blt t0, s0, loop
	addi a7, zero, 4
	la a0, primo
	ecall
	addi a7, zero, 10
	ecall
nao_eh:
	addi a7, zero, 4
	la a0, nao
	ecall
	addi a7, zero, 10
	ecall
	