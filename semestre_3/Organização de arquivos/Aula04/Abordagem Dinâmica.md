
- Indicada para aplicações interativas que acessam arquivos altamente voláteis


# Registros de Tamanho Fixo

- **Lista encadeada** de registros eliminados
- lista: constitui-se dos RRNs dos registros marcados como logicamente removidos
- Utilizamos Pilha
	- Remove e empilha (coloca o índice do RRN no TOPO e o TOPO no começo do registro)

- **Remoção**:
	- Marca o registro como logicamente removido
	- Insere o registro na lista de registros logicamente removidos (empilha)

- **Inserção**
	- Remove o registro da lista de registros logicamente removidos (desempilha)
	- Insere dados no espaço do registro desempilhado

## Exemplo

![[Pasted image 20260320194534.png]]

- **Removendo o registro com RRN = 1**

![[Pasted image 20260320194607.png]]

- *Repare no índice empilhado na lista*
- *Repare no asterisco sinalizando que o registro foi removido*

![[Pasted image 20260320195424.png]]

- Removendo o registro 3 e depois o 0
## Implementação

 - A **busca** é igual da estática (olhar implementação da abordagem estática)

- **REMOVE**

```
Remove por RRN:
	abre o arquivo p/ escrita
	ler o valor do proxRRN do registro de cabeçalho
	Se o RRN < proxRRN
		byte offset <-- RRN * tamanho_registro
		posicionar a posição corrente em byte offset
		
		Se o registro não está marcado como removido
			marcar como removido
			//empilha
			valor_TOPO armazenado no registro
			TOPO <- RRN
		Senão registro não encontrado
	
	Senão registro não encontrado
	
	fechar arquivo
```

- **INSERE**

```
Insere um registro:
	abre o arquivo p/ escrita
	ler o valor de proxRRN (do cabeçalho) e do topo do registro do cabeçalho
	Se topo == -1
		byteoff set = proxRRN * tamanho_registro
		posicionar a posição corrente em byte offset
		
		escrever o registro
		escrever proxRRN++ no registro de cabeçalho
	
	Senão
		byte offset = topo * tamanho_registro
		posicionar a posição corrente em byte offset
		topo <- RRN prox registro da pilha
		escrever o registro
	
	fechar arquivo
	
```