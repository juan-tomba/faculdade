
### Subconjunto de instruções do RISC - V

- **Tipo R**: add, sub, and, or
- **Tipo I**: lw
- **Tipo S**: sw
- **Tipo B**: beq

### Possíveis implementações

- **Monociclo**: Todas as instruções são executas em um *único ciclo de clock*
- **Multiciclo**: As *instruções são quebradas em etapas*, e cada etapa é executada em um único ciclo de clock (não vamos implementar)
- **Pipeline**: As instruções são quebradas em etapas, e *etapas de múltiplas instruções são executadas ao mesmo tempo*

### Etapas

- Instruction Fetch (IF)
- Instruction Decode (ID)
- Execution-ULA (EX)
- Memory Access (MEM)
- Write back (WB)

- **Exemplos**
	- Tipo R: IF, ID, EX, WB
	- lw - IF, ID, EX, MEM, WB - *mais lenta*
	- sw - IF, ID, EX, MEM
	- beq - IF, ID, EX, MEM(não usa acesso a memória)