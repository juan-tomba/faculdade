#include <stdio.h>

void bubble_sort(int v[], int n){
    int i, j, aux, flag = 1;

    /*Quando:
    i = 0 --> j = 0; j < n - 1             (n - 1 comparações)
    i = 1 --> j = 0; j < n - 1 - 1         (n - 2 comparações)
    .
    .
    i = n - 2 --> j = 0; j < n-(n-2) - 1   (1 comparação)
    i = n - 1 --> j = 0; j < n-(n-1) - 1   (0 comparações)

    ODD:
    Não Ordenado: n²
    Ordenado: n
    */

    for(i = 0; i < n && flag; i++){
        flag = 0;
        for(j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                flag = 1;
            }
        }
    }
}

int main(){
    int v[] = {3,5,2,6,8,1,5,2,10,11}; //n = 10

    bubble_sort(v, 10);

    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }

}