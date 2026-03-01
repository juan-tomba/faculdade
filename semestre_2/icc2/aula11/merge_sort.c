#include <stdio.h>
#include <stdlib.h>

// Função para intercalar (merge) dois subarrays já ordenados
void merge(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Vetores temporários
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    // Copia os elementos para os vetores temporários
    for (int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    // Faz a fusão
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L (se houver)
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R (se houver)
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }

    // Libera memória
    free(L);
    free(R);
}

// Função recursiva do Merge Sort
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a metade esquerda
        mergeSort(v, inicio, meio);
        // Ordena a metade direita
        mergeSort(v, meio + 1, fim);
        // Junta as duas metades
        merge(v, inicio, meio, fim);
    }
}

int main() {
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    mergeSort(v, 0, n - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
