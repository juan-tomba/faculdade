### Busca Binária

*Dados ordenados*
**O elemento buscado é comparado ao elemento do meio do arranjo**
*Se igual, busca bem-sucedida*
*Se menor, busca-se na metade inferior do arranjo*
*Se maior, busca-se na metade superior do arranjo*

**A não recursiva é mais rápida, além de nao empilhar chamadas**
*O(log(n)), pois cada comparação reduz o número de possíveis candidatos por um fator de 2*

*A busca binária pode ser usada com a organização da tabela sequencial indexada*

### Busca por interpolação

**Pode ser até mais rápido que a BB**
*Caso os elementos estejam uniformemente ordenados*
**meio = inf + (sup – inf) * ((x – A[inf]) / (A[sup] – A[inf]))**

*O(log(log(n))) se as chaves estiverem uniformemente distribuídas*
*Se as chaves não estiverem uniformemente distribuídas, a busca por interpolação pode ser tão ruim quanto uma busca sequencial*

**Em situações práticas, as chaves tendem a se aglomerar em torno de determinados valores e não são uniformemente distribuídas**
*Ex: tem mais nomes começando com S, do que com Q*

### ABB (Árvores Binárias de Busca)

**Lista Encadeada**
*Eficiente para inserção e remoção dinâmica de elementos, mas ineficiente para busca*

**Lista Sequencial (ordenada)**
*Eficiente para busca, mas ineficiente para inserção e remoção de elementos*

**SOLUÇÃO: ABB**

**Os elementos a esquerda da raiz R, são todos menores que R**
**No nível N, tem (2N - 1) elementos**

**Em cada nó, compara-se o elemento buscado com o elemento presente**
*Se menor, percorre-se a subárvore esquerda*
*Se maior, percorre-se a subárvore direita*

**No pior caso, ele passa por todos os níveis da árvore**

**OS ELEMENTOS A SEREM INSERIDOS DEVEM ESTAR BALANCEADOS!!**
*Se ja estiverem ordenados, a árvore vira uma lista*

**Inserção: O(logn), mas pode ser O(n) caso esteja ordenada**
**Busca: O(logn)**

*Varios tipos de árvores: AVL, rubro-negra, treap, LLRB, etc*