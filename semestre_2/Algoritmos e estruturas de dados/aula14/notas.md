### Árvore Binária

**Cada nó pode ter 0,1 ou 2 filhos**
**Sequencial ou Dinâmica**
*Dinâmica: gerenciamento de mémoria*

**Busca**
*Sequencial Ordenada: Posso usar Busca binária*
*Sequencial não ordenada: busca sequencial*
*Dinâmica ordenada: sequencial*
*Dinâmica não ordenada: sequencial*
**Mas agora podemos usar Árvore Binária!!!!!**

### Tipos

**Árvore estritamente binária: tem nós com 0 ou 2 filhos (exceto folhas)**
*numéro máximo de passos na busca: profundidade da árvore*

**Árvore Binária Completa Cheia (ABCC): é uma arvore estritamente binária, todos os seus nós-folhas estão no mesmo nível**
*n = nós, d = profundidade*
*Numero total de nós de uma ABCC de profundidade d? n = 2^d+1 - 1*
*d = log(n + 1) - 1*

**Árvore Binaria Completa (ABC)**
*Cada nó folha está no nível d-1 ou d*
*o nível d-1 está totalmente preeenchido*
*os nós em d estão mais a esquerda*

**Árvore perfeitamente balanceada**
*Para cada nó, o número de nós de suas sub-arvores esquerda e direita, difere em no máximo 1*

**Árvore binária balanceada**
*Para cada nó, as alturas de suas duas sub-árvores, diferem no máximo 1*
*Toda arvore binaria perfeitamente balanceada é Balanceada, mas o inverso não é necessariamente verdade*

## Questão

**Qual a altura máxima de uma AB com n nós**
*Altura n-1 (insere tudo na direita/esquerda, até virar uma lista)*

**Qual a altura mínima de uma AB com n nós**
*H_min = log(n) (parte inteira ou piso)*

### Implementação ABCC Sequencial

**Vantagens: espaço so p/ armazenar conteúdo**
**Desvantagem: espaços vagos se a arvore não é completa por níveis, ou tem retirada de elementos**

**Filho_esquerdo = 2*i + 1**
**Filho_direito = 2*i +2**
**Pai = (i-1)/2 (parte inteira ou piso)**
