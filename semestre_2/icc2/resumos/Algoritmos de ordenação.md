## Tabela de Complexidades de Algoritmos de Ordenação

| Algoritmo                                | Melhor Caso | Caso Médio  | Pior Caso   | Espaço Extra | Estável? | Observações                                                                   |
| ---------------------------------------- | ----------- | ----------- | ----------- | ------------ | -------- | ----------------------------------------------------------------------------- |
| **Bubble Sort**                          | O(n)        | O(n²)       | O(n²)       | O(1)         | ✔️       | Melhor caso com o vetor ordenado.                                             |
| **Selection Sort**                       | O(n²)       | O(n²)       | O(n²)       | O(1)         | ❌        | Número de comprações constante.                                               |
| **Insertion Sort**                       | O(n)        | O(n²)       | O(n²)       | O(1)         | ✔️       | Eficiente para vetor ordenado.                                                |
| **Shell Sort**                           | O(n log n)  | ~O(n^1.5)   | O(n²)       | O(1)         | ❌        | Depende da escolha de gaps.                                                   |
| **QuickSort (mediana de 3)**             | O(n log n)  | O(n log n)  | O(n²)       | O(log n)     | ❌        | O uso da mediana ajuda a evitar o pior caso                                   |
| **HeapSort**                             | O(n log n)  | O(n log n)  | O(n log n)  | O(1)         | ❌        | Sempre O(nlogn)                                                               |
| **MergeSort**                            | O(n log n)  | O(n log n)  | O(n log n)  | O(n)         | ✔️       | Precisa de memória extra.                                                     |
| **Counting Sort (Contagem dos Menores)** | O(n + k)    | O(n + k)    | O(n + k)    | O(n + k)     | ✔️       | Exige intervalo finito de valores.                                            |
| **Radix Sort**                           | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k)     | ✔️       | Baseado nos dígitos dos valores (menos significativo para mais significativo) |

\* varia conforme a sequência de incrementos (gaps) escolhida.
