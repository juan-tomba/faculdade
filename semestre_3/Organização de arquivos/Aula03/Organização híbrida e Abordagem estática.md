# Organização híbrida

- Exemplos de aplicação na vida real:
	- Tamanho fixo:
		- CPF, NUSP, telefone, CEP, idade, etc
	- Tamanho variável
		- nome, endereço, e-mail, etc...
- **Misturar campos de tamanho fixo com campos de tamanho variável**

## Escolha da organização em registros

| **Tamanho Fixo**                                        | **Tamanho variável**                                   |
| :------------------------------------------------------ | :----------------------------------------------------- |
| Acesso direto por RRN                                   | Dificuldade na busca                                   |
| Pode ter desperdício de memória ou truncamento de dados | Não existe desperdício de memória/truncamento de dados |
|                                                         |                                                        |
### Exemplo

- Tamanho fixo:
	- número: inteiro (4 bytes)
	- telefone: string de 13 caracteres (13 bytes)
- Tamanho variável
	- nome: string de tamanho variável 
	- rua: string de tamanho variável 
	- cidade: string de tamanho variável

![[Pasted image 20260316102414.png]]

# Abordagem Estática de Reuso de Espaço

- Inserção de registros
- Remoção de registros
	- remoção lógica
		- atribui um valor facultativo (por exemplo "/")
		- ou utiliza um campo extra (removido ? 0 ou 1)
- Atualização de registros

- **Técnica não faz nada em um intervalo $\Delta$t**
- Durante $\Delta$t:
	- **(remoção lógica)**
	- Registros removidos são marcados, mas não reutilizados
	- Inserções no final do arquivo
	- Buscas desconsideram os registros marcados como removidos
- Após $\Delta$t:
	- **(remoção física)**
	- Programa é executado para reconstruir o arquivo
	- Todos os registros removidos são descartados

### Características

- Pode ser aplicada a registros de tamanho fixo e variável
- Frequência de aplicação da técnica:
	- Depende da aplicação
	- Depende da porcentagem de registros marcados como removidos

### Exemplo

![[Pasted image 20260316104037.png]]

- Remoção (lógica) dos registros com RRN = 1 e RRN = 3

![[Pasted image 20260316104143.png]]


