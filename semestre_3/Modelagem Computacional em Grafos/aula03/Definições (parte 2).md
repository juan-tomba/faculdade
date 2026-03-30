## Subgrafo

- Um subgrafo G’ = (V’, E’) de um grafo G = (V, E) é um grafo tal que V’ $\subseteq$ V e E’ $\subseteq$ E.

![[Pasted image 20260323194850.png]]

## Subgrafo gerador

- Um subgrafo gerador G’ = (V’, E’) de um grafo G = (V, E) é um grafo tal que V’ = V e E’ $\subseteq$ E

![[Pasted image 20260323203230.png]]

## Subgrafo Induzido

- Um subgrafo induzido G’ = (V’, E’) de um grafo G = (V, E) é um grafo tal que V’ $\subseteq$ V e E’ contém todas as arestas em E que tem as duas extremidades em V’

![[Pasted image 20260323203615.png]]



## Grafo Conexo

- Um grafo G = (V, E) é conexo quando existe um caminho entre cada par de vértices de G, caso contrário, G é desconexo. 
- Para um grafo orientado, a decisão é feita SEM considerar a orientação da arestas.
- Um grafo é totalmente desconexo quando não possui arestas.
- Todo grafo euleriano é conexo e todos os seus vértices possuem grau par.

![[Pasted image 20260323195021.png]]

## Dígrafo Fortemente Conexo

- Um grafo orientado D = (V, E) é dito ser fortemente conexo quando existe um caminho entre cada par de vértices (x,y) e também entre (y,x).

![[Pasted image 20260323195149.png]]

## Componente Conexa

- É um **subgrafo conexo máximo**
- Isso significa que é uma parte do grafo onde todos os vértices estão conectados por caminhos entre si, e não é possível adicionar mais vértices a esse subgrafo mantendo-o conexo.

![[Pasted image 20260323195413.png]]

- **{v1, v2, v5, v7}**
    - Todos estão ligados entre si por caminhos (v1–v2–v5–v7).
- **{v3, v4}**
    - Esses dois estão conectados entre si, mas não com os outros.
- **{v6}**
    - Está isolado (não tem arestas).

# Exercícios de fixação

![[Pasted image 20260323195531.png]]

- São cíclicos: a/b/c
- Todos são conexos
- São:
	- Eurelianos: nenhum
	- Hamiltonianos: b/c


![[Pasted image 20260323200910.png]]

- Como todos os quatro vértices possuem um **grau ímpar**, o trajeto é impossível


## Grafo Bipartido

- Um grafo G = (V, E) é bipartido quando o seu conjunto de vértices V puder ser dividido em dois subconjuntos V1 , V2 tais que toda aresta do conjunto E une um vértice de V1 a outro vértice de V2

![[Pasted image 20260323201305.png]]

- **Grafo bipartido completo**
	- Todo vértice de V1 DEVE estar conectado a TODOS os vértices de V2.
	- Número de arestas: num de vértices V1 x num de vértices V2

## Complemento

- Denomina-se complemento de um grafo G = (V, E) a um grafo G’ = (V’, E’) tal que **V’ = V** e **E’ é complementar a E.**

![[Pasted image 20260323202028.png]]

## Isomorfismo

- Dois grafos G = (V, E) e G’ = (V’, E’) são isomorfos entre si se existe correspondência entre os seus vértices e arestas de forma a preservar a relação de incidência
- Dois grafos são isomorfos se eles forem "o mesmo grafo", apenas desenhados de formas diferentes.

![[Pasted image 20260323202401.png]]


## Árvore

- Uma árvore é um **grafo:** 
	- *Conexo*: Você consegue chegar de qualquer ponto a qualquer outro.
	- *Acíclico*: Não existem ciclos (não dá para "dar uma volta" e voltar ao mesmo ponto sem repetir o caminho).

![[Pasted image 20260323202617.png]]

## Árvore Enraizada

- Uma árvore enraizada é uma árvore orientada em que há um vértice (raiz) do qual todas as arestas se afastam.

![[Pasted image 20260323202811.png]]

## Árvore geradora

- Uma árvore geradora G’ = (V’, E’) de um grafo é um **subgrafo gerador que é uma árvore**

![[Pasted image 20260323203355.png]]

## Floresta

- Conjunto de árvores

![[Pasted image 20260323202854.png]]


# Exercícios de fixação 2

![[Pasted image 20260323203706.png]]

- **Solução:**

![[Pasted image 20260323205332.png]]

