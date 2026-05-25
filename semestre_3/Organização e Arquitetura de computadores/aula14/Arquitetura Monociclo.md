- Instruções executadas em um único ciclo de clock
- *Ciclo de Clock* de tamanho da instrução mais lenta

## Conjunto Reduzido

| Tipo | Nome      | Exemplo           | Formato dos Bits                                                 |
| ---- | --------- | ----------------- | ---------------------------------------------------------------- |
| R    | Register  | add rd, rs1, rs2  | f7 (7) \| rs2 (5) \| rs1 (5) \| f3 (3) \| rd (5) \| opcode (7)   |
| I    | Immediate | lw rd, imm(rs1)   | imm (12) \| rs1 (5) \| f3 (3) \| rd (5) \| opcode (7)            |
| S    | Store     | sw rs2, imm(rs1)  | imm (7) \| rs2 (5) \| rs1 (5) \| f3 (3) \| imm (5) \| opcode (7) |
| B    | Branch    | beq rs1, rs2, imm | imm (7) \| rs2 (5) \| rs1 (5) \| f3 (3) \| imm (5) \| opcode (7) |
| J    | Jump      | jal rd, imm       | imm (20) \| rd (5) \| opcode (7)                                 |
## Implementações

##### Tipo R

![[PHOTO-2026-05-19-10-42-09.jpg]]

##### Tipo I

![[PHOTO-2026-05-19-10-42-30.jpg]]

##### Tipo S

![[PHOTO-2026-05-19-10-43-29.jpg]]

##### Tipo B

![[PHOTO-2026-05-19-10-44-27.jpg]]


### Flags

```
se t0 == t1 PC = PC + (imm * 2)
senao PC = PC + 4
```

- ZONC
	- zero
	- overflow
	- negative
	- carry out


### ULA

![[Pasted image 20260521084226.png]]