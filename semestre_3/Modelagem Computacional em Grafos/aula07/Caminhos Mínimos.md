
Dado um **grafo ponderado** G(V, E) com função de peso `w: E → ℝ`, queremos encontrar o caminho de **menor custo total** entre dois vértices.

O **peso de um caminho** `p = <v₀, v₁, ..., vₖ>` é simplesmente a soma dos pesos de cada aresta percorrida:

$$w(p) = \sum_{i=1}^{k} w(v_{i-1},\ v_i)$$

O **peso do caminho mínimo** entre `u` e `v` é chamado de `δ(u,v)`:

$$\delta(u,v) = \begin{cases} \min{w(p)\ :\ u \xrightarrow{p} v} & \text{se existe algum caminho de } u \text{ para } v \ \infty & \text{caso contrário} \end{cases}$$

> Um **caminho mínimo** é qualquer caminho `p` tal que `w(p) = δ(u,v)`.  
> Podem existir vários caminhos mínimos — o que importa é o peso total, não qual exatamente você escolhe.

---

## Variantes do Problema

|Variante|Descrição|Como resolver|
|---|---|---|
|**Fonte única**|De um vértice `s` para todos os outros|Dijkstra ou Bellman-Ford|
|**Destino único**|De todos para um vértice `t`|Inverter direção das arestas + fonte única|
|**Par único**|De `u` para `v` específico|Caso particular do fonte única (não tem atalho)|
|**Todos os pares**|Entre todo par (u, v)|Rodar fonte única para cada vértice|

---

## Conceitos

###  Subcaminhos de caminhos mínimos

> Se `p = [v₁, ..., vᵢ, ..., vⱼ, ..., vₖ]` é o caminho mínimo de `v₁` até `vₖ`,  
> então o **trecho interno** de `vᵢ` até `vⱼ` também é o caminho mínimo entre esses dois.

**Por quê isso importa?** Porque significa que caminhos mínimos têm **subestrutura ótima** — podemos construir a solução global a partir de soluções locais. É isso que permite os algoritmos funcionarem de forma incremental.

---

###  Arestas de peso negativo

Arestas com peso negativo são **permitidas** na maioria dos casos — o problema só surge com **ciclos negativos**.

- **Sem ciclo negativo:** o caminho mínimo está bem definido, mesmo que passe por arestas negativas.
- **Com ciclo negativo acessível a partir de `s`:** o "caminho mínimo" tende a −∞, pois basta ficar circulando no ciclo para diminuir o custo indefinidamente. Não faz sentido falar em mínimo.

> Dijkstra **não suporta** pesos negativos.  
> Bellman-Ford **suporta** e ainda **detecta** ciclos negativos.

---

###  Representando o caminho (vetor de predecessores)

Os algoritmos não guardam o caminho explicitamente — guardam apenas o **predecessor** de cada vértice no vetor `π[v]`.

Para reconstruir o caminho de `s` até `v`, basta seguir os predecessores de trás pra frente:

```
print_path(G, s, v):
  se v == s:
      imprime s                         ← chegou na origem, para aqui

  senão se π[v] == NIL:
      imprime "nenhum caminho de s para v"   ← v não é alcançável

  senão:
      print_path(G, s, π[v])           ← vai recursivamente ao predecessor
      imprime v                         ← imprime v ao voltar da recursão
```

> A recursão imprime os vértices **na ordem certa** (de s até v) porque imprime `v` só depois de resolver tudo antes dele.

---

## Relaxamento 

Todos os algoritmos de caminho mínimo são baseados em **relaxamento**. A ideia é simples:

> Mantenho uma estimativa `d[v]` da distância de `s` até `v`.  
> Inicialmente `d[v] = ∞` para todos (exceto `d[s] = 0`).  
> Relaxar uma aresta `(u, v)` significa: _"se eu chegar em `v` passando por `u`, fica mais barato?"_  
> Se sim, atualizo.

### Inicialização

```
Initialize-single-source(G, s):
  para cada vértice v em V[G]:
      d[v]  = ∞      ← ainda não sabemos nada
      π[v]  = NIL    ← sem predecessor
  d[s] = 0           ← distância da origem até ela mesma é 0
```

### Relax(u, v, w)

```
Relax(u, v, w):
  se d[v] > d[u] + w(u, v):     ← passar por u é mais barato?
      d[v] = d[u] + w(u, v)     ← atualiza a estimativa de v
      π[v] = u                   ← u agora é o predecessor de v no caminho
```

> **Exemplo:** `d[u] = 5`, `w(u,v) = 2`, `d[v] = 9`  
> → `5 + 2 = 7 < 9` → atualiza: `d[v] = 7`, `π[v] = u`
> 
> Se `d[v] = 6`: `5 + 2 = 7 > 6` → não atualiza (já temos um caminho melhor para v)

---

## Algoritmo de Dijkstra

**Restrição importante:** só funciona com pesos **≥ 0**.

### Ideia geral

O algoritmo divide os vértices em dois grupos:

- **S** = vértices "fechados", cuja distância mínima já foi determinada definitivamente.
- **Q** = vértices ainda em aberto (fila de prioridade pelo menor `d[v]`).

A cada iteração, pega o vértice `u` com menor estimativa em Q, o "fecha" (move para S) e relaxa todas as arestas que saem de `u`. Como os pesos são não-negativos, a menor estimativa atual **nunca vai melhorar depois** — por isso podemos fechar com segurança.

### Pseudocódigo comentado

```
Dijkstra(G, w, s):
  Initialize-single-source(G, s)    ← d[s]=0, d[v]=∞ para o resto

  S = ∅                              ← conjunto de vértices fechados (vazio no início)
  Q = V[G]                           ← fila de prioridade com todos os vértices

  enquanto Q ≠ ∅:                    ← enquanto ainda há vértices para processar

      u = Extract-Min(Q)             ← pega o vértice com menor d[u] em Q
                                     ← (na primeira iteração, será o próprio s com d=0)

      S = S ∪ {u}                    ← fecha u: sua distância mínima está definida

      para cada v em Adj[u]:         ← explora todos os vizinhos de u
          Relax(u, v, w)             ← tenta melhorar a estimativa de cada vizinho
```

### Exemplo

![[Pasted image 20260609133624.png]]

### Por que funciona com pesos não-negativos?

Quando extraímos `u` com o menor `d[u]`, sabemos que **nenhum outro caminho chegará em `u` mais barato** — porque qualquer outro caminho que ainda não foi explorado passa por vértices com `d ≥ d[u]`, e os pesos só aumentam (ou mantêm). Com pesos negativos isso quebra: um caminho mais longo poderia custar menos.

### Complexidade

|Estrutura para Q|Complexidade|
|---|---|
|Array simples|O(V²)|
|Heap binário|O((V + E) log V)|
|Heap de Fibonacci|O(V log V + E)|

---

## DAG Shortest Path (Grafos Acíclicos Dirigidos)

Quando o grafo é um **DAG** (sem ciclos de qualquer tipo), dá para resolver de forma ainda mais eficiente.

### Ideia

Em um DAG, existe uma **ordenação topológica** dos vértices — uma ordem linear tal que toda aresta `(u, v)` tem `u` antes de `v`. Se relaxarmos as arestas nessa ordem, garantimos que quando processamos `u`, todas as arestas que chegam em `u` já foram relaxadas. Assim, **cada aresta é relaxada exatamente uma vez**.

### Pseudocódigo comentado

```
DAG-Shortest-Path(G, w, s):

  Ordenar topologicamente os vértices de G
                                     ← garante que processamos u antes de seus sucessores

  Initialize-single-source(G, s)    ← d[s]=0, d[v]=∞ para o resto

  para cada vértice u (na ordem topológica):
                                     ← processa cada vértice uma única vez

      para cada v em Adj[u]:         ← para cada aresta saindo de u
          Relax(u, v, w)             ← tenta melhorar d[v] passando por u
```

**Complexidade: Θ(V + E)** — linear no tamanho do grafo.

> Vantagens sobre Dijkstra:
> 
> - Mais rápido (sem heap, sem repetição)
> - **Aceita pesos negativos** (não há ciclos, então não há problema)

### Exemplo

![[Pasted image 20260609133813.png]]


---

## Algoritmo de Bellman-Ford

**Quando usar:** grafo geral (pode ter ciclos, pode ter arestas negativas).

### Ideia

O caminho mínimo sem ciclos entre quaisquer dois vértices tem **no máximo |V| - 1 arestas**. Bellman-Ford relaxa **todas as arestas** repetidamente por `|V| - 1` rodadas. A cada rodada, pelo menos mais um vértice tem sua distância correta definida.

Depois das `|V| - 1` rodadas, faz uma verificação extra: se ainda for possível relaxar alguma aresta, existe um **ciclo negativo**.

### Pseudocódigo comentado

```
Bellman-Ford(G, w, s):

  Initialize-single-source(G, s)         ← d[s]=0, d[v]=∞ para o resto

  para i = 1 até |V| - 1:               ← repete |V|-1 vezes
                                          ← (caminho sem ciclo tem no máx |V|-1 arestas)

      para cada aresta (u, v) em E[G]:   ← percorre TODAS as arestas do grafo
          Relax(u, v, w)                 ← tenta melhorar d[v]

  ── verificação de ciclo negativo ──

  para cada aresta (u, v) em E[G]:       ← percorre todas as arestas mais uma vez
      se d[v] > d[u] + w(u, v):         ← se ainda dá pra relaxar...
          retorna FALSE                   ← ...existe ciclo negativo! distâncias indefinidas

  retorna TRUE                            ← sem ciclo negativo, d[v] = δ(s,v) para todo v
```

**Complexidade: O(V · E)**

> Por que `|V| - 1` rodadas?  
> Um caminho simples (sem repetir vértices) tem no máximo `|V| - 1` arestas.  
> Na rodada `i`, garantimos que todos os caminhos com até `i` arestas foram considerados.  
> Após `|V| - 1` rodadas, todos os caminhos mínimos foram encontrados — se ainda der pra relaxar, é porque há ciclo negativo.

### Exemplo

![[Pasted image 20260609134113.png]]

---

## Comparativo Geral

|Algoritmo|Pesos negativos|Detecta ciclo negativo|Grafo com ciclos|Complexidade|
|---|:-:|:-:|:-:|---|
|**Dijkstra**|❌|❌|✅|O((V+E) log V)|
|**DAG Shortest Path**|✅|❌ (não precisa)|❌ (só DAG)|Θ(V+E)|
|**Bellman-Ford**|✅|✅|✅|O(V·E)|

---

## Propriedades Formais 

> Essas propriedades garantem a corretude dos algoritmos.

- **Desigualdade triangular:** para qualquer aresta `(u,v) ∈ E`: `δ(s,v) ≤ δ(s,u) + w(u,v)`
    
    - O caminho mínimo direto nunca é pior do que dar uma volta por outro vértice.
- **Propriedade do limite superior:** sempre `d[v] ≥ δ(s,v)`. Uma vez que `d[v]` atinge `δ(s,v)`, nunca diminui mais.
    
    - As estimativas só melhoram, e param no valor ótimo.
- **Propriedade de nenhum caminho:** se não existe caminho de `s` a `v`, então `d[v] = δ(s,v) = ∞` para sempre.
    
- **Propriedade de convergência:** se `s → u → v` é um caminho mínimo e `d[u] = δ(s,u)` antes de relaxar `(u,v)`, então depois do relaxamento `d[v] = δ(s,v)` permanentemente.
    
    - Ou seja: relaxar na ordem certa "fixa" as distâncias corretas de forma definitiva.