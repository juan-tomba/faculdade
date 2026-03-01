#include <stdio.h>

int pot(int base, int exp){
    int result = 1;
    for (int i = 0; i < exp; i++){
        result *= base;
    }
    return result;
}

int fat(int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int main(){
    int x;
    scanf("%d", &x);
    float resul = 1;
    for(int i = 2; i < 10; i++){
        float prov =(float) pot(x, ((i * 2) - 2)) / fat(((i * 2) - 1));
        if (i % 2 == 0) {
            resul -= prov;
        }
        else {
            resul += prov;
        }
    }
    printf("Resultado: %f\n", resul);
    return 0;
}