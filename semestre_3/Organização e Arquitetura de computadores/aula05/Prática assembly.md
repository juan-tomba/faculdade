## Exemplos realizados em sala

- **Exemplo 1**: Programa que lê um número fornecido pelo usuário
	- Se numero > 0, imprime "Hello World++!"
	- Se número < 0, imprime "Hello World--!"

- **Exemplo 2**: Programa que lê um número fornecido pelo usuário, e calcula o fatorial dele
	- Utiliza um loop, que multiplica **Var_acumuladora** * **Var_decrementadora**

### Acesso a memória

![[Pasted image 20260318141750.png]]

![[Pasted image 20260318141832.png]]


### Conteúdo

- *align* - **alinhar dados ou instruções na memória em endereços específicos**, normalmente múltiplos de algum valor (como 2, 4, 8, 16 bytes).
- Exemplo Prático
	- string "hello world!" ocupa até o byte 13
	- se eu quero declarar um word (4 bytes) ele tem que ser armazenado em algum byte múltiplo de 4
	- **o align r vai te falar em qual múltiplo de $2^{r}$ você pode armazenar**
		- align 0 -> align $2^{0}$ = 1 byte
		- align 2 -> align $2^{2}$ = 4 bytes

- Utilizamos o simulador RARS 1.5, para executar o código, aperta na ferramenta na barra de cima, e depois em run

