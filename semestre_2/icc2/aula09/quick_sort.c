#include <stdio.h>

void quick_sort(int v[], int ini, int fim){
    int i, j, pivo, aux;

    pivo = v[ (ini + fim) / 2];
    i = ini;
    j = fim;
    
    do {
        while(v[i] < pivo) i++;
        while(v[j] > pivo) j--;

        if (i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
            
        }
    } while( i < j);

    if (j > ini) quick_sort(v, ini, j);
    if (i < fim) quick_sort(v, i, fim);
}

int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    quick_sort(v, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}