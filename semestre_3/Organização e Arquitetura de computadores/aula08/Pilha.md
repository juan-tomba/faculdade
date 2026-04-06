- ponteiro para pilha: sp (stack pointer)
- pilha cresce no sentido contrário
-  /imagem caderninho/

## Empilhar

- 1) "Reserva espaço na pilha"
	- 3 palavras => 3 * 4  bytes
	- addi sp, sp, -12

- 2) Armazenar os valores na pilha
	- sw ra, 0(sp)
	- sw s0, 4(sp)
	- sw a0, 8(sp)

## Desempilhar

- 1) Ler os conteúdos empilhados
	- lw s0, 4(sp)
	- lw a0, 8(sp)
	- lw ra, 0(sp)

- 2) Atualizar o stack pointer
	- addi sp, sp, 12

## Fatorial recursivo

- Em C

```c
int main(int n){
	if (n == 0)
		return 1;
	else
		return (n * fatorial(n-1));
}
```

# Tipos de Instruções

- 6 Tipos
- R = Register -> add rd, rs1, rs2       | f7 (7 bits) |rs2(5 bits)| rs1(5 bits) | f3(3 bits)| rd(5bits)| opcode(7 bits)|
- I = Imeediate -> lw rd, imm(rs1)     | imm (12 bits) | rs1(5 bits) | f3(3 bits)| rd(5bits)| opcode(7 bits)|
- S = Store -> sw rs2, imm(rs1)          | imm (7 bits) |rs2(5 bits)| rs1(5 bits) | f3(3 bits)| imm (5 bits)| opcode(7 bits)|
- B = Branch -> beq rs1, rs2, imm     | imm (7 bits) |rs2(5 bits)| rs1(5 bits) | f3(3 bits)| imm (5 bits)| opcode(7 bits)|
- U = Upper -> lui rs1, imm               | imm (20 bits)| rd(5bits)| opcode(7 bits)|
- J = Jump -> jal rd, imm                   | imm (20 bits)| rd(5bits)| opcode(7 bits)|

| Tipo | Nome      | Exemplo           | Formato dos Bits                                                 |
| ---- | --------- | ----------------- | ---------------------------------------------------------------- |
| R    | Register  | add rd, rs1, rs2  | f7 (7) \| rs2 (5) \| rs1 (5) \| f3 (3) \| rd (5) \| opcode (7)   |
| I    | Immediate | lw rd, imm(rs1)   | imm (12) \| rs1 (5) \| f3 (3) \| rd (5) \| opcode (7)            |
| S    | Store     | sw rs2, imm(rs1)  | imm (7) \| rs2 (5) \| rs1 (5) \| f3 (3) \| imm (5) \| opcode (7) |
| B    | Branch    | beq rs1, rs2, imm | imm (7) \| rs2 (5) \| rs1 (5) \| f3 (3) \| imm (5) \| opcode (7) |
| U    | Upper     | lui rd, imm       | imm (20) \| rd (5) \| opcode (7)                                 |
| J    | Jump      | jal rd, imm       | imm (20) \| rd (5) \| opcode (7)                                 |

- **RV32I** - soma, sub, and, or, shifts inteiros