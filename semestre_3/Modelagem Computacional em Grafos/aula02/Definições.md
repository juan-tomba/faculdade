
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
	- os grafos b) e c) são simples
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

- O grau **d(v)** de um vértice corresponde ao número de vértices adjacentes a v (ou ao número de arestas incidentes a v).
![[Pasted image 20260309211721.png]]

- Em **grafos orientados**:
	- O Grau de Saída **d_out(v)** de um vértice v corresponde ao número de arestas divergentes (que saem) de v.
		- Um vértice com d_out(v) = 0, é chamado de **sumidouro** (ou sorvedouro)
	- O Grau de Entrada **d_in(v)** de um vértice v corresponde ao número de arestas convergentes (que chegam) de v
		- Um vértice com d_in(v) = 0, é chamado de **fonte**.
- Se um grafo possuir todos os vértices com o mesmo grau, é chamado de **regular**


# Exercício de fixação

![[Pasted image 20260309212411.png]]


- 1) 
	- O grafo a) é regular, porque todos os vértices tem d(v) = 3
	- O grafo b) não é regular, pois existem vértices com graus diferentes d(v2) = 3 e d(v3) = 4
- 2)
	- o v5 é fonte e o v4 sumidouro


## Grafos Valorados

- Um **grafo valorado V(a)** consiste de um conjunto finito não vazio de arestas(A) e vértices(V) com pesos
- O conjunto A consiste de triplas distintas da forma (v, w, valor), em que v e w são vértices pertencentes a V e valor é um número real.
- Grafos podem ter arestas com pesos representando a "força" da relação entre os vértices:
- **EXEMPLO**
	- Quão minha amiga é uma certa pessoa ?
		- 0: inimiga
		- 5: colega
		- 10: amiga

## Caminho

- Um **caminho** entre X e Y é uma sequência de vértices/arestas que une os dois pontos
- Um caminho de k-vértices é formado por k-1 arestas (v1 ,v2 ), (v2 ,v3 ) ... (vk-1 , vk ), e o valor de k-1 é o comprimento do caminho.

![[Pasted image 20260309221453.png]]

- P é o comprimento do caminho

- Um **caminho é simples** se todas os vértices forem distintos
	- O caminho P = v3, v1, v2 é simples
	- O caminho P= v3 ,v4 ,v3 ,v1 NÃO é simples

## Circuito e ciclo

- Um **circuito** é um caminho P = v1 ,v2 , ..., vk , vk+1, onde v1 = vk+1. Um **ciclo** é um circuito onde todos os vértices são distintos (exceto pelo primeiro e pelo último).
- Um grafo é **cíclico** se apresentar ao menos um ciclo.

![[Pasted image 20260309221958.png]]

## Caminho Hamiltoniano

- Caminho Hamiltoniano é aquele que **contém cada vértice do grafo exatamente uma vez**
- Um ciclo v1 ,v2 , ..., vk , vk+1 é hamiltoniano quando o caminho v1 ,v2 , ..., vk for um caminho hamiltoniano.
- Um grafo é Hamiltoniano se contiver um ciclo hamiltoniano.

![[Pasted image 20260309222242.png]]


- v1 ,v6 ,v5 ,v2 ,v3 ,v4 é hamiltoniano
- v6 ,v5 ,v4 ,v3 ,v2 ,v1 ,v6 é um ciclo hamiltoniano


## Caminho Euleriano

- Caminho Euleriano é aquele que **contém cada aresta do grafo exatamente uma vez**.
- Um grafo é Euleriano se há um circuito em G que contenha todas as suas arestas.

- *Teorema de Euler* - para um grafo ser euleriano:
	- Ser **conexo**
	- **Todos** os seus vértices precisam ter **grau par**

![[Pasted image 20260309222403.png]]



