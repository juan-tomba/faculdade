### Introdução a árvores

**Estrutura Hierarquica (não linear)**
**Para procurar um n-elemento, não precisa passar pela ED inteira**
*Ex: livro->cap(N)->seção(N)*

**Busca por "Busca Binária"**
**T = {r} U {T1} U {T2} U .... U {Tn}**
*r é um nó especial da árvore, chamado raiz da árvore*

**Representação pode ser por: Identação, grafos e conjuntos alinhados**
*Grau de um nó é o número de sub-árvores relacionadas áquele nó*
*Nós com grau 0 (sem sub-árvores), são chamados de FOLHA*
*Se cada nó de uma árvores possui um grau máximo, então esse é o GRAU DA ÁRVORE*

## Terminologia das árvores

**Cada raiz ri da sub-árvore Ti, é chamada de filho de r. Assim como neto, etc..**
**Caminho: sequência não vazia de nós, onde o i-ésimo nó ri da sequência é pai de ri+1**
*Ex: P={r1,r2,.....,rk}*

**Comprimento: O comprimento de um caminho P(exemplo) é igual a k-1**

**Altura de um nó: comprimento do caminho mais longo do nó r, até uma folha**
**Altura de uma árvore: é igual a altura da raiz r de T**
**Profundidade: o comprimento do ÚNICO CAMINHO em T, entre a raiz r e o nó ri**
**Nível: um conjunto de nós com a mesma profundidade**
*raiz está no nível 0*

**Ascendência e Descendência**