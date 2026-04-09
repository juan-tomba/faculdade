## DFS - busca em profundidade

- Cores:
	- branco = inicialização
	- cinza = esta visitando seus filhos/vizinhos
	- preto = visitou e voltou
- Utiliza uma **Pilha (LIFO)** ou **Recursão**.
- Explora um caminho até chegar a um beco sem saída e depois volta para a última bifurcação.
- O (|V| + |E|)
- finalizou = coloca na lista (nao quando vai, so quando volta)
- Aplicações
	- **Ordenação Topológica:** Fundamental para modelar dependências (ex: ordem de matérias na faculdade).
	- **Detecção de Ciclos:** Verificar se há um caminho que volta ao início.
	- **Componentes Conexos:** Identificar "ilhas" isoladas dentro do grafo.
----
## BFS: busca em largura
- Propaga igual uma "mancha de óleo"
- O(|V| + |E|) , com V = vértices e E = aresta
- Inicialização: O(|V|)
- Utiliza uma **Fila (FIFO)**.
- Aplicações:
	- **Caminho Mínimo:** Em grafos **não valorados** (sem pesos nas arestas), a BFS garante encontrar o caminho com o menor número de arestas.
	- **Redes de Contato:** Achar "amigos em comum" ou o nível de separação entre pessoas.
