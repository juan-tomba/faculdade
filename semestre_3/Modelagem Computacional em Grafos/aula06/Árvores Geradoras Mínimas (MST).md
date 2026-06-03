- O problema só tem solução se G é conexo
- Assim, assumimos G conexo
	- obs: Um **grafo conexo** é aquele em que existe um caminho válido entre qualquer par de vértices

- A solução para esse problema será sempre uma árvore

- Árvore Geradora (Spanning Tree) de um grafo G é um sub-grafo de G que contém todos os seus vértices e, ainda, é uma árvore
- Árvore Geradora Mínima (Minimum Spanning Tree – MST) é a árvore geradora de um grafo valorado cuja soma dos pesos associados às arestas é mínimo, i.e., é uma árvore geradora de custo mínimo

## Aplicações

- Construir estradas para interligar n cidades (com custo mínimo de construção de estradas)

# Algoritmo Genérico

```
Generic-MST(G)  
	A ← ∅  
	  
	enquanto A não tiver todos os vértices conectados faça  
		escolha uma aresta segura (u, v)  
		A ← A ∪ {(u, v)}  
	  
	retorne A
```

- *aresta segura* -> uma aresta que pode ser adicionada sem estragar a solução.
- Quando todos os vértices estiverem conectados, `A` vira uma árvore geradora mínima (MST).
- O algoritmo vai ligando os vértices aos poucos, sempre escolhendo uma aresta “boa” até conectar tudo com o menor custo possível.

![[Pasted image 20260525220414.png]]

# Algoritmo de Prim

- Gera uma **Minimum Spanning Tree** do grafo ponderado G
- Algoritmo Guloso
- Complexidade (tempo): O(n\*m)
	- n: número de vértices 
	- m: número de arestas
- Exemplo Lúdico: Rede de cabo entre cidades
- **Ele sempre compara todas as arestas disponíveis (tipo, ele pode voltar na recursão)**
- Ver exemplo slide com linhas 

```
Prim-MST (G)
	Escolha um vértice s para iniciar a árvore
	enquanto “Há vértices que não estão na árvore”
		Selecione a aresta com menor peso adjacente a um vértice pertencente à 
		árvore e a outro não pertencente à árvore
		Insira a aresta selecionada e o respectivo vértice na árvore
		
	fim-enquanto
```

```
Algoritmo Resumido (G)
	Pega vértice A
	Escolhe a aresta com menor peso conectada
	Vai fazendo isso sem repetir vértices até acabar

```


![[Pasted image 20260519145311.png|600]]

# Algoritmo de Kruskal

- Em vez de ir crescendo a árvore a partir de um vértice, ordena as arestas e vai escolhendo as com menor peso (enquanto não formas ciclos)
- *Mais eficiente que Prim em grafos esparsos*
- O(E log E)
- Algoritmo Guloso
- **NÃO FORMAR CICLOS**

```
Algoritmo Resumido (G)
	Ordena em ordem crescente as arestas
	Começa por um grafo sem arestas (vértice isolado)
	Para cada aresta (na ordem):
		Se não forma ciclo, adicione à solução
		Senão, ignore
	Pare quando tiver (V - 1) arestas
```

![[Pasted image 20260519151255.png]]

- Para evitar ciclos, utilize **Union-Find (Disjoint Set)**


## Comparação

| **Kruskal**                 | **Prim**                  |
| --------------------------- | ------------------------- |
| Escolhe arestas globais     | Cresce a partir de um nó  |
| Usa ordenação               | Usa fila de prioridade    |
| Melhor para grafos esparsos | Melhor para grafos densos |
