### Execução Monociclo

- Problema ciclo de clock - *tamanho da maior instrução*
- lw - maior instrução
- Tempo ciclo de clock : 10 ms

| Tipo                        | sw      | add      |
| --------------------------- | ------- | -------- |
| lê instrução mem            | ✓       | ✓        |
| lê operador / decodificador | ✓       | ✓        |
| ULA (calcular end)          | ✓       | operação |
| lê dado da mem dados        | escreve | ✗        |
| escreve no BcoReg           | ✗       | ✓        |

### Pipeline

- Divide a execução da instrução em etapas e executa etapas diferentes de instruções diferentes no mesmo ciclo de clock

- **Etapas**
	- IF - Instruction Fetch - Mem Instrução - 3 ms
	- ID - Instruction Code - UC e BcoReg - 1 ms
	- EX - Execution - ULA - 2 ms
	- MEM - Memory Acess - Mem Dados - 3 ms
	- WB - Write Back - BcoReg - 1 ms

![[IMG_7251.jpeg]]

- *Bem mais rápido que a monociclo*
- *Primeira instrução*: 15 ms, *Segunda instrução*: 3 ms, *Terceira instrução*: 3 ms

## Conflito Estrutural

- É um dos três tipos clássicos de hazard (hazards de pipeline)
	- conflito estrutural
	- conflito de dados
	- conflito de controle
- Acontece quando **duas ou mais instruções precisam usar o mesmo hardware ao mesmo tempo**, mas o processador não consegue atender todas simultaneamente.
- Com isso, o pipeline precisa:
	- parar uma instrução (stall/bolha)
	- ou atrasar algum estágio
