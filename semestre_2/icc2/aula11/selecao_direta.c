#include <stdio.h>

void selection_sort(int v[], int n) {
    int aux, menor;
    for(int i = 0; i < n; i++){
        menor = i;
        for(int j = i; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = v[menor];
            v[menor] = v[i];
            v[i] = aux;
        }
    }
}


int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    selection_sort(v, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}