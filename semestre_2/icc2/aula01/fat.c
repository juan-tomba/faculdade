#include <stdio.h>

int fat(int n){
    if (n == 0){
        return 1;
    }
    return n * fat(n - 1);
}

int fibonacci(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;
    scanf("%d", &n);
    int fatorial = fat(n);
    int fib = fibonacci(n);
    
    printf("Fatorial: %d\n", fatorial);
    printf("Fibonacci: %d\n", fib);
    return 0;
}    