
- **Vértices** : pontos
- **Arestas**: Linhas
- **Grau**: Número de arestas incidentes
- **Ordem**: Número de vértices
### Multigrafo

- Quando um grafo possui mais de uma aresta interligando os mesmos dois vértices, chama-se **arestas múltiplas** (ou arestas paralelas). Ele é chamado de **Multigrafo** (ou grafo múltiplo).
![[Pasted image 20260304151402.png]]

Um **Grafo simples** é um grafo que **NÃO** possui arestas múltiplas

### Grafo trivial e Grafo vazio

- **Grafo Trivial**: se for de ordem 1 ou 0
- **Grafo Vazio**: Pode ser representado com G = $\varnothing$

### Laço

- Se um grafo possui o mesmo vértice como extremos, como: e = (X,X), é dito que este grafo possui um **Laço**
![[Pasted image 20260304152001.png]]

### Vértices adjacentes

- Os vértices X e Y são considerados **Adjacentes** (ou vizinhos) quando forem extremos de uma mesma aresta, como e = (X,Y)

![[Pasted image 20260304152208.png]]

### Arestas adjacentes

- Duas arestas são **adjacentes** quando possuírem um extremo/vértice em comum
- A aresta e =(v3 ,v4) é dita incidente a v3 e a v4

![[Pasted image 20260304153341.png]]

- (v1,v2) é adjacente a (v2,v5)
- (v1,v2) não é adjacente a (v3,v4)
### Grafo completo

- Um grafo é considerado **completo** caso todos os seus vértices forem adjacentes
- Um grafo completo Kn possui n(n-1)/2 arestas

![[Pasted image 20260304154115.png]]

- Neste exemplo, temos:
	- a: 1 aresta
	- b: 3 arestas
	- c: 6 arestas
	- d: 10 arestas
# Exercícios de fixação

![[Pasted image 20260304162106.png]]

- 1)
	- a) ordem: 5 | num arestas: 9
	- b) ordem: 8 | num arestas: 13
	- c) ordem: 4 | num arestas: 6
- 2)
	- somente o grafo c) é completo
- 3)
	- os fragos b) e c) são simples
- 4)
	- São adjacentes a v3: v1, v2, v4, v5
	- (v1, v5), (v2, v5), (v4, v5), (v1, v3), (v1, v3), (v2, v3), (v4, v3), 


### Aplicações

- Caminhos de rodovias
- Rede de relacionamentos
### Orientados

- Um grafo **orientado** (ou dígrafo) possui um conjunto de vértices e arestas de pares ordenados (com orientação)
- Em um grafo orientado, cada aresta possui uma direção


![[Pasted image 20260305140117.png]]

- Na aresta (v3,v1) por exemplo:
	- v3 é divergente
	- v1 é convergente
### Grau



# Exercício de fixação

**ATÉ CAMINHO EURELIANO**

