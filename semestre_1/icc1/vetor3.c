#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}