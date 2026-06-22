
## Visão Geral

|Algoritmo|Tipo|Grafo|Pesos negativos?|
|---|---|---|---|
|[[#Algoritmo Genérico (MST)]]|MST|Não-direcionado|✗|
|[[#Algoritmo de Prim]]|MST|Não-direcionado|✗|
|[[#Algoritmo de Kruskal]]|MST|Não-direcionado|✗|
|[[#Dijkstra]]|Caminho mínimo|Direcionado/Não-dir.|✗|
|[[#DAG Shortest Path]]|Caminho mínimo|DAG (direcionado acíclico)|✓|
|[[#Bellman-Ford]]|Caminho mínimo|Direcionado|✓|
|[[#Ford-Fulkerson]]|Fluxo máximo|Direcionado|—|

---

## Árvore Geradora Mínima (MST)

### Algoritmo Genérico (MST)

**Ideia:** Cresce uma MST adicionando, a cada passo, uma aresta segura — ou seja, uma aresta leve que cruza um corte que respeita o conjunto de arestas já escolhido. É o esqueleto teórico do qual Prim e Kruskal são instâncias.

**Invariante:** O conjunto $A$ sempre é subconjunto de alguma MST.

```
GENERIC-MST(G, w):
  A = ∅
  enquanto A não forma uma árvore geradora:
    encontre aresta (u,v) segura para A
    A = A ∪ {(u,v)}
  retorne A
```

|Implementação|Complexidade|
|---|---|
|Genérico (abstrato)|depende da estratégia de escolha|

---

### Algoritmo de Prim

**Ideia:** Começa de um vértice arbitrário e expande a árvore sempre adicionando a aresta de menor peso que conecta um vértice já na árvore a um vértice fora dela. Usa uma fila de prioridade para eficiência.

**Analogia:** "Cresce como uma mancha" — sempre escolhe o vizinho mais barato.

```
PRIM(G, w, r):
  para cada u ∈ V:
    key[u] = ∞,  π[u] = NIL
  key[r] = 0
  Q = V  (fila de prioridade mínima)
  enquanto Q ≠ ∅:
    u = EXTRACT-MIN(Q)
    para cada v ∈ Adj[u]:
      se v ∈ Q e w(u,v) < key[v]:
        π[v] = u
        key[v] = w(u,v)
```

|Implementação|Complexidade|
|---|---|
|Array simples|$O(V^2)$|
|Heap binário + lista de adjacência|$O(E \log V)$|
|Heap de Fibonacci + lista de adjacência|$O(E + V \log V)$|

> 💡 **Melhor para:** grafos densos (array) ou grafos esparsos com Fibonacci heap.

---

### Algoritmo de Kruskal

**Ideia:** Ordena todas as arestas por peso e as adiciona à MST uma a uma, desde que não formem ciclo. Usa Union-Find (estrutura de conjuntos disjuntos) para verificar ciclos eficientemente.

**Analogia:** "Visão global" — considera todas as arestas do grafo ordenadas.

```
KRUSKAL(G, w):
  A = ∅
  para cada vértice v: MAKE-SET(v)
  ordene arestas de G por peso crescente
  para cada (u,v) em ordem:
    se FIND-SET(u) ≠ FIND-SET(v):
      A = A ∪ {(u,v)}
      UNION(u, v)
  retorne A
```

|Implementação|Complexidade|
|---|---|
|Ordenação + Union-Find ingênuo|$O(E \log E)$|
|Ordenação + Union-Find com union by rank + path compression|$O(E \log V)$|

> 💡 **Melhor para:** grafos esparsos onde $E \ll V^2$.

---

## Caminhos Mínimos

### Dijkstra

**Ideia:** Algoritmo guloso que mantém um conjunto de vértices com distância mínima já calculada (conjunto $S$) e um conjunto de candidatos em uma fila de prioridade. A cada passo, extrai o vértice de menor distância estimada e relaxa suas arestas.

**Restrição:** Não funciona com arestas de peso negativo.

```
DIJKSTRA(G, w, s):
  INITIALIZE-SINGLE-SOURCE(G, s)
  S = ∅,  Q = V
  enquanto Q ≠ ∅:
    u = EXTRACT-MIN(Q)
    S = S ∪ {u}
    para cada v ∈ Adj[u]:
      RELAX(u, v, w)
```

|Implementação|Complexidade|
|---|---|
|Array / matriz de adjacência|$O(V^2)$|
|Heap binário + lista de adjacência|$O(E \log V)$|
|Heap de Fibonacci|$O(E + V \log V)$|

> 💡 **Melhor para:** grafos com pesos não-negativos; é o mais usado na prática.

---

### DAG Shortest Path

**Ideia:** Explora o grafo na ordem topológica, relaxando as arestas de cada vértice à medida que ele é processado. Como o grafo é acíclico (DAG), a ordem topológica garante que cada vértice é processado após todos os seus predecessores.

**Vantagem:** Funciona com pesos negativos e é mais eficiente que Dijkstra para DAGs.

```
DAG-SHORTEST-PATHS(G, w, s):
  ordene topologicamente os vértices de G
  INITIALIZE-SINGLE-SOURCE(G, s)
  para cada vértice u em ordem topológica:
    para cada v ∈ Adj[u]:
      RELAX(u, v, w)
```

|Implementação|Complexidade|
|---|---|
|Ordenação topológica + relaxamento|$\Theta(V + E)$|

> 💡 **Melhor para:** DAGs com ou sem pesos negativos. Complexidade ótima.

---

### Bellman-Ford

**Ideia:** Relaxa todas as arestas do grafo $|V| - 1$ vezes. Após $k$ iterações, garante que os caminhos de no máximo $k$ arestas foram calculados corretamente. Também detecta ciclos de peso negativo.

```
BELLMAN-FORD(G, w, s):
  INITIALIZE-SINGLE-SOURCE(G, s)
  para i = 1 até |V| - 1:
    para cada aresta (u,v) ∈ E:
      RELAX(u, v, w)
  para cada aresta (u,v) ∈ E:
    se d[v] > d[u] + w(u,v):
      retorne FALSO  ← ciclo negativo detectado!
  retorne VERDADEIRO
```

|Implementação|Complexidade|
|---|---|
|Padrão|$O(VE)$|

> 💡 **Melhor para:** grafos com pesos negativos onde Dijkstra não pode ser usado. Mais lento, mas mais geral. ⚠️ Retorna `FALSE` se houver ciclo de peso negativo alcançável a partir de $s$.

---

## Fluxo Máximo

### Ford-Fulkerson

**Ideia:** Enquanto existir um caminho aumentante (da fonte $s$ ao sumidouro $t$) na rede residual, aumenta o fluxo ao longo desse caminho pelo valor da capacidade residual mínima (gargalo). Termina quando não há mais caminhos aumentantes.

**Conceitos-chave:**

- **Rede residual $G_f$:** mostra capacidades restantes para enviar mais fluxo
- **Caminho aumentante:** qualquer caminho $s \to t$ em $G_f$
- **Gargalo (bottleneck):** capacidade residual mínima no caminho

```
FORD-FULKERSON(G, s, t):
  para cada aresta (u,v): f(u,v) = 0
  enquanto existir caminho p de s a t em G_f:
    c_f(p) = min{ c_f(u,v) : (u,v) ∈ p }
    para cada aresta (u,v) ∈ p:
      f(u,v) += c_f(p)
      f(v,u) -= c_f(p)
```

|Implementação|Complexidade|
|---|---|
|Ford-Fulkerson (capacidades inteiras, DFS)|$O(E \cdot \|f^*\|)$ — pseudopolinomial|
|Edmonds-Karp (BFS para caminho aumentante)|$O(VE^2)$ — polinomial|

> 💡 **Teorema Max-Flow Min-Cut:** o fluxo máximo de $s$ a $t$ é igual à capacidade mínima de um corte $(S, T)$ que separa $s$ de $t$. ⚠️ Ford-Fulkerson puro pode não terminar com capacidades irracionais — prefira Edmonds-Karp.

---

## Comparativo Rápido

```
Problema            Algoritmo         Complexidade (típica)
─────────────────────────────────────────────────────────────
MST                 Prim (heap bin.)  O(E log V)
MST                 Kruskal           O(E log V)
Caminho mínimo      Dijkstra          O(E log V)
Caminho mínimo DAG  DAG SP            Θ(V + E)        ← ótimo
Caminho mínimo      Bellman-Ford      O(VE)
Fluxo máximo        Edmonds-Karp      O(VE²)
```
