### Sub-Grafo

- Um sub-grafo G2 (V2,E2) de um grafo G1 (V1,E1), blablabla

### Sub-Grafo induzido

- Se o sub-grafo G2 de G1 satisfaz

### Sub-grafo gerador

- Sub-grafo gerador


# Algoritmo de Prim

- Gera uma **Minimum Spanning Tree** do grafo ponderado G
- Algoritmo Guloso
- Complexidade (tempo): O(n\*m)
- Exemplo Lúdico: Rede de cabo entre cidades
- **Ele sempre compara todas as arestas disponíveis (tipo, ele pode voltar na recursão)**
- Ver exemplo slide com linhas 

```
Prim-MST (G)
	
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
