#include <stdio.h>

void contagem_menores(int v[], int n){
    int i, j, aux[n], B[n];

    memset(aux, 0, sizeof(int) * n);
    memcpy(B, v, sizeof(int) * n);

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(v[i] < v[j]){
                aux[j]++;
            }
            else{
                aux[i]++;
            }
        }
    }

    for(i = 0; ;){
        
    }
}

int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    contagem_menores(v, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}