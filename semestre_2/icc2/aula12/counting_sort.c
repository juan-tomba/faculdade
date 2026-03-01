#include <stdio.h>

void counting_sort(int v[], int n){
    int i, maior, menor, intervalo;

    for(i = 0; i < n; i++){
        if(v[i] > maior){
            maior = v[i];
        }
        if(v[i] < menor){
            menor = v[i];
        }
    }

    intervalo = maior - menor + 1;
    int aux[intervalo];
    memset(aux, 0, sizeof(int) * intervalo);

    for(i = 0; i < n; i++){
        aux[v[i] - menor]++;
    }

    int j = 0;
    for(i = 0; i < intervalo; i++){
        while(aux[i] > 0){
            v[j] = i + menor;
            aux[i]--;
            j++;
        }
    }
}

int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    counting_sort(v, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}