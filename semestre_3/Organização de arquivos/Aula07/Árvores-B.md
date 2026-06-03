## Introdução

- Método genérico para armazenamento/recuperação de dados
	- arquivos volumosos
	- acesso rápido aos dados
	- custo mínimo de overhead
- *Balanceada*
- cada nó da arvore tem 4kb de chaves (ordenadas)
- aponta pro filho direito e esquerdo
- Exemplo de estrutura de árvore B:
  ![[Pasted image 20260519170737.png]]



## Pesquisa (busca)

- Recursiva
- **TODA BUSCA COMEÇA PELO NÓ RAIZ**
- Busca binária (por isso ordenado)

```
se RRN da página corrente é -1
	então retorna não encontrou
	senão pesquisa a página corrente procurando a chave de busca
		se encontrou
			então retorna a referência apropriada para o registro no arquivo de dados
			senão procura a chave de busca no nó filho usando o RRN para a página apropriada
		fim se
fim se
```

## Inserção

- Sempre realizada no **nó folha**
- Situações que devem ser analisadas:
	- *Árvore vazia* - situação inicial
	- *Overflow no nó raiz* - demais inserções
	- *Inserção nos nós folhas* - preenchimento dos nós folhas
- **Pior Caso** : inserção ordenada

```
se existe espaço no nó
	então insere ordenado
	senao // split 1 to 2
		cria 1 novo nó
		distribui o mais uniforme possivel as chaves
		promove 1 chave
		
```
