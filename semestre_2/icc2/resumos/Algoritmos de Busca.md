

| Algoritmo                     | Tipo / Estrutura Base          | Ideia Principal                                                                 | Complexidade Média | Observações Importantes |
|-------------------------------|---------------------------------|----------------------------------------------------------------------------------|--------------------|--------------------------|
| **Busca Sequencial**          | Lista / Vetor linear            | Percorre todos os elementos até encontrar o valor desejado.                      | O(n)               | Simples de implementar, mas ineficiente para grandes volumes de dados. |
| **Busca Sequencial Indexada** | Lista com índices parciais      | Usa um índice auxiliar que aponta para blocos do vetor, reduzindo o número de comparações. | O(√n)              | Compromisso entre simplicidade e desempenho; útil em arquivos ordenados. |
| **Busca por Interpolação**    | Vetor ordenado (numérico)       | Estima a posição do elemento com base na distribuição dos valores.               | O(log log n)       | Mais eficiente que a binária se os dados forem uniformemente distribuídos. |
| **Busca Binária**             | Vetor ordenado                  | Divide o vetor ao meio repetidamente até encontrar o elemento.                   | O(log n)           | Extremamente eficiente, mas requer dados ordenados. |
| **Busca em Árvores**          | Árvores (BST, AVL, etc.)        | Navega pela estrutura hierárquica comparando o valor procurado com cada nó.      | O(log n) (AVL) / O(n) (não balanceada) | Árvores balanceadas (como AVL) mantêm eficiência; árvores comuns podem degradar. |
| **Hashing**                   | Tabela hash                     | Usa uma função de espalhamento para mapear chaves diretamente a posições.        | O(1) (média) / O(n) (pior caso) | Muito rápido em média; depende da qualidade da função hash e do tratamento de colisões. |
