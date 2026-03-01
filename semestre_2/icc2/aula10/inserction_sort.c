#include <stdio.h>

void inserction_sort(int v[], int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i - 1; j >= 0 && aux < v[j]; j--){
            v[j + 1] = v[j];
        }
        v[j + 1] = aux;
    }
}

int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    inserction_sort(v, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}