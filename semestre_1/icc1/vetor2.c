#include <stdio.h>

int main(){
    int vetor[15];
    for (int i = 0; i < 15; i++){
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 15; i++){
        if (i % 2 != 0) {
            printf("%d ", vetor[i]);
        }
    }

    return 0;
}