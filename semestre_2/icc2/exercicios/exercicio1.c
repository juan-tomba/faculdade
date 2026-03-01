#include <stdio.h>

int conta(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return((2*conta(n - 1)) + (3*conta(n-2)));
}

int main(){
    int n;
    scanf("%d", &n);
    int resul = conta(n);
    printf("Resultado: %d\n", resul);

    return 0;
}