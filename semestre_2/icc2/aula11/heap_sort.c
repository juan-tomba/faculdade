#include <stdio.h>

void rearranjar_heap(int v[], int i, int tamanho_do_heap){
    int aux, maior, esq, dir;
    esq = 2*i+1;
    dir = 2*i+2;
    maior = i;

    if((esq < tamanho_do_heap) && (v[esq] > v[maior])){
        maior = esq;
    }
    if((dir < tamanho_do_heap) && (v[dir] > v[maior])){
        maior = dir;
    } 

    if(i != maior){
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        rearranjar_heap(v, maior, tamanho_do_heap);
    }
}

void construir_heap(int v[], int n){
    int i;

    for(i = n/2 - 1; i>=0; i--){
        rearranjar_heap(v, i, n);
    }
}

void heap_sort(int v[], int n){
    int i, aux, tam_heap = n;
    construir_heap(v, n);

    for(int i = 0; i < n; i++){
        aux = v[0];
        v[0] = v[tam_heap - 1];
        v[tam_heap - 1] = aux;
        tam_heap--;
        rearranjar_heap(v, 0, tam_heap);
    }
}

int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    heap_sort(v, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}