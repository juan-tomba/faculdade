#include <stdio.h>

int main() {
    double vc, a; // velocidade do carro e aceleração do caminhão
    double t, x, vt;

    printf("Digite a velocidade constante do carro (m/s): ");
    scanf("%lf", &vc);

    printf("Digite a aceleracao do caminhao (m/s^2): ");
    scanf("%lf", &a);

    if (a <= 0 || vc <= 0) {
        printf("A aceleracao e velocidade devem ser positivas.\n");
        return 1;
    }

    // tempo de encontro
    t = (2 * vc) / a;

    // posicao do encontro
    x = vc * t;

    // velocidade do caminhão no encontro
    vt = a * t;

    printf("\n--- Resultados ---\n");
    printf("Tempo de encontro: %.2f s\n", t);
    printf("Posicao de encontro: %.2f m\n", x);
    printf("Velocidade do carro no encontro: %.2f m/s\n", vc);
    printf("Velocidade do caminhao no encontro: %.2f m/s\n", vt);
    printf("Aceleracao do carro: 0 m/s^2 (constante)\n");
    printf("Aceleracao do caminhao: %.2f m/s^2\n", a);

    return 0;
}
