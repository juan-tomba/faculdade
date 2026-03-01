#include <stdio.h>

int main() {
    unsigned long long fib[86]; 
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 85; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%llu\n", fib[n]);
    }

    return 0;
}
