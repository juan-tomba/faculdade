- prox RRN = proximo RRN disponivel
```
Busca por RRN
	registro de cabeçalho: prox RRN: 4
	Abrir o arquivo p/ leitura
	Ler o valor do prox RRN do registro de cabeçalho
	Se RRN < prox RRN
		byteoffset = RRN * tamanho_Registro
		posicionar a posição corrente em byte offset
		
		se o registro não está marcado como removido
			ler o registro e exibir a saída padrão
		senão registro não encontrado
	
	Senão registro não encontrado
	fechar arquivo

```

```
Remove por RRN:
	abre o arquivo p/ escrita
	ler o valor do proxRRN do registro de cabeçalho
	Se o RNN < proxRRN
		byte offset = RRN * tamanho_registro
		posicionar a posição corrente em byte offset
		
		Se o registro não está marcado como removido
			marcar como removido
		Senão registro não encontrado
	
	Senão registro não encontrado
	
	fechar arquivo
```

```
Insere um registro:
	abre o arquivo p/ escrita
	ler o valor de proxRRN (do cabeçalho)
	byteoff set = proxRRN * tamanho_registro
	posicionar a posição corrente em byte offset
	
	escrever o registro
	escrever prox RRN++ no registro de cabeçalho
	
	fechar arquivo
	
```

 como fazer para registros dinâmicos sem RRN?