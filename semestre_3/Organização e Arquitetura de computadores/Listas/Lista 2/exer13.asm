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
	li t0, 1                # t0 = Primeiro termo (F0)
	li t1, 1            # t1 = Segundo termo (F1)
	li s1, 0            # s1 = Contador de iterações (i = 0)
loop:
	beq s0, s1, fim
	addi a7, zero, 1
	add a0, zero, t0
	ecall
	addi a7, zero, 4
	la a0, str
	ecall
	add t2, t0, t1
	add t0, zero, t1
	add t1, zero, t2
	addi s1, s1, 1
	j loop

fim:
	addi a7, zero, 10
	ecall