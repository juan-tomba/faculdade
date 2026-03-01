#include <stdio.h>
#include <string.h>

typedef struct {
    int kindex, pos;
} bloco_indice;

void cria_indice(bloco_indice indice[], int tam_indice, int v[], int n){
    int i = 0;
    int n_por_indice = n / tam_indice;

    while(i < tam_indice){
        int pos = i * n_por_indice;
        indice[i].kindex = v[pos];
        indice[i].pos = pos;
        i++;
    }
}

int busca_sequencial_indexada(int v[], int n, bloco_indice indice[], int tam_indice, int x){
    int i = 0;

    while(i < tam_indice && x > indice[i].kindex){
        i++;
    }
    int pos = indice[i-1].pos;
    while(pos < n){
        if (x == v[pos])
            return pos;
        pos ++;
    }
    return -1;

}

int main(){
    int v[] = {1,5,8,14,16,18,20,22,25,28,30,31,32,35,38,40,42,46,48,50}; // n = 20
    bloco_indice indice[5];
    cria_indice(indice, 5, v, 20);

    for(int i = 0; i < 5; i++){
        printf("%d, %d\n", indice[i].kindex, indice[i].pos);
    }
    printf("\n");
    printf("%d\n", busca_sequencial_indexada(v, 48, indice, 5, 20));

    return 0;
}