- Duas representações para grafos
	- **Matriz de Adjacências**
	- **Listas Lineares de Adjacências**

## Matriz de Adjacências

- Dado um grafo G = (V, E), a matriz de adjacências M é uma matriz de ordem n x n, tal que:
	- n = número de vértices M
	- [i,j] = 1, se existir aresta de i a j M
	- [i,j] = 0, se NÃO existir aresta de i a j

- Forma mais simples
- Propriedades:
	- É simétrica para um grafo não direcionado
	- Armazenamento: O($n^{2}$)
	- Teste se aresta (i,j) está no grafo: O(1)

- **Exemplo**

![[Pasted image 20260323210749.png]]

## Estrutura de Adjacências

- É a forma mais usada em algoritmos eficientes. Em vez de uma tabela, usamos um **vetor de listas encadeadas**.
- **Vantagem:** Economiza muita memória ($O(V + A)$). Só guardamos o que realmente existe.
- **Desvantagem:** Para saber se $A$ se conecta a $B$, você tem que percorrer a lista do $A$ até achar o $B$ (tempo $O(grau\_do\_vertice)$).

- **Exemplo**

![[Pasted image 20260323211609.png]]


## Comparação

![[Pasted image 20260323211811.png]]

![[Pasted image 20260323211825.png]]

# Exercício de Fixação

![[Pasted image 20260323211923.png]]

![[Pasted image 20260323213253.png]]