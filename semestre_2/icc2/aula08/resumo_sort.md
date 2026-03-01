# Resumo: Métodos de Ordenação (Parte 1)

## Problema da Ordenação

-   **Definição**: organizar uma sequência de elementos segundo uma
    relação de ordem (ex: k1 ≤ k2 ≤ ... ≤ kn).
-   **Utilidade**: facilita busca e recuperação de dados (listas
    telefônicas, dicionários, bancos de dados).
-   **Custo**: 25% do tempo de computação pode envolver ordenação.
-   **Tipos**:
    -   **Interna**: registros cabem na memória principal.
    -   **Externa**: registros armazenados em disco/fita.
-   **Estabilidade**: elementos com mesma chave mantêm a ordem original.

### Estratégias de Ordenação

-   **Por registros**: troca os próprios elementos.
-   **Por endereços**: troca ponteiros para os registros.

## Comparação de Algoritmos

-   Complexidade medida pelo número de comparações.
-   Entrada: vetor de inteiros, busca de ordem crescente.

------------------------------------------------------------------------

## Algoritmos Baseados em Troca

### Bubble Sort

-   **Ideia**: percorre o vetor repetidamente, trocando elementos
    adjacentes fora de ordem.

-   Após cada iteração, o maior elemento se posiciona no final.

-   **Pseudocódigo**:

    ``` c
    void bubblesort(int v[], int n) {
        int i, j, aux;
        for (i=0; i<n; i++)
            for (j=0; j<n-1; j++)
                if (v[j] > v[j+1]) {
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
    }
    ```

### Bubble Sort Aprimorado

-   **Otimização**: parar quando nenhuma troca for realizada (vetor já
    ordenado).
-   **Complexidade**:
    -   Pior caso: O(n²).
    -   Melhor caso: O(n) (vetor já ordenado).
    -   Espaço: O(1).
-   **Comparações totais**: (n-1) + (n-2) + ... + 1 = O(n²).

------------------------------------------------------------------------

## Conclusões

-   Bubble Sort é simples, mas ineficiente para grandes vetores.
-   Melhor caso otimizado é linear, mas em geral é quadrático.
-   Futuras aulas incluem algoritmos mais eficientes (ex: Quick Sort).
