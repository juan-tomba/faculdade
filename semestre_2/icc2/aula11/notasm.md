## Seleção Direta


## Heap-Sort

**Utiliza heap (tipo uma arvore)**
*Pai tem que ser maior que os filhos*
*Se não tem filhos, é uma folha*
*Folhas ficam o mais a esquerda possivel*
**Filhos do nó k:**
*filho esquerdo = 2k + 1*
*filho direito = 2k + 2*
*Pai do nó k: (k-1)/2*
*Folhas de n/2 em diante*

**construir_heap: O(n)**
**heap_sort: O(nlogn)**
 

 **CONSIDERAÇÕES FINAIS**
 Heap-sort é útil para arquivos com muitos registros
 Complexidade do anel interno do algoritmo
 Quick-sort é cerca de 2x mais rápido
 Heap-sort é melhor que o Shell-sort para grandes arquivos
