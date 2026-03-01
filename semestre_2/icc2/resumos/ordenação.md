### Resumo algoritmos de ordenação:

**Melhor para busca com itens aleatórios: Quick Sort**
**Melhor para vetor já ordenado: Insertion Sort**
**Melhor para vetor inversamente ordenado: Quick Sort**

### Observações

**Heap sort e Merge Sort úteis para aplicações que não podem tolerar variações no tempo esperado para ordenação**
**Utilizar Inserction Sort para vetores com menos que 25 elementos**


## Insertion Sort(aula10)

*Interessante para arquivos com menos de 20 elementos*
*Pode ser mais eficiente do que algoritmos com menor comportamento assintótico*
*Método estável*
*Melhor que o bubble-sort*
*Arranjo já ordenado: O(n)*

## Selection(aula11)

*Somente é vantajoso quanto ao número de movimentos de registros: O(n)*
*Pode ser usado para arquivos com registros grandes, desde que o tamanho não exceda 1000 elementos*

## Shell Sort(aula10)

*Mesmo para arquivos grandes, é 2x mais lento que o Quick Sort*
*Não tem caso ruim*
*Melhor para arquivos parcialmente ordenados*

## Heap Sort(aula11)

*Cerca de 2x mais lento que o Quick Sort*
*Não precisa de memória adicional*
*Sempre O(nlogn)*

## Merge Sort(aula11)

*Precisa de memória adicional*
*Tambem sempre O(nlogn)*

## Quick Sort (aula09)

*Mais eficiente (GOAT)*
*Caso escolha errado o pivô, pode ter odd quadrática*
*Recursividade exige um pouco de memória adicional*
*Pivô = mediana de 3 elementos*

### Outros algoritmos

**Shake-sort ou método da coqueteleira**
**Tree-sort ou método da árvore binária**
**Bucket-sort ou método do balde**