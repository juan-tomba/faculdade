#include <stdio.h>

int inverso_existe(int num, int d) {
    int t = 0, novo_t = 1;
    int r = d, novo_r = num;

    // algoritmo de euclides estendido
    while (novo_r != 0) {
        int quociente = r / novo_r;

        int temp_t = t - quociente * novo_t;
        t = novo_t;
        novo_t = temp_t;

        int temp_r = r - quociente * novo_r;
        r = novo_r;
        novo_r = temp_r;
    }
    if (t < 0){
        t = t + d;
    }
    return t;
}

int main() {
    int num, d;
    printf("Digite o numero que deseja encontrar o inverso: \n");
    scanf("%d", &num);
    printf("Digite o d de Z(d) que deseja encontrar o inverso: \n");
    scanf("%d", &d);

    int a = num, b = d, resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    if (a != 1) {
        printf("O inverso nao existe, pois o mdc(%d, %d) = %d\n", num, d, a);
    } else {
        int inverso = inverso_existe(num, d);
        printf("O inverso de %d em Z(%d) = %d\n", num, d, inverso);
    }

    return 0;
}
