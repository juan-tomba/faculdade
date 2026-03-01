#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;

    printf("Calculadora de Bhaskara\n");

    printf("Coloque as Variaveis a: ");
    scanf("%f", &a);

    printf("Coloque as Variaveis b: ");
    scanf("%f", &b);

    printf("Coloque as Variaveis c: ");
    scanf("%f", &c);
    printf("\n\n");

    float quadrado = b * b,
          delta = quadrado - (4 * a * c),
          divisor = 2 * a,
          bhaskara;

    if (delta < 0) {
        printf("Conta impossivel delta negativo\n");
        return 0;
    } else {
        bhaskara = sqrt(delta);
        printf("Delta: %f\n\n", delta);
    }

    printf("Resultado= %.2f %.2f", (-b + bhaskara) / divisor, (-b - bhaskara) / divisor);

    return 0;
}