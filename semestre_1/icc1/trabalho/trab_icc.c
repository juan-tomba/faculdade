#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf ("%d", &n);
    double matriz[n][n], final[n][n], alpha_i, alpha_j;
    double pi=3.141592;
    // Lê Entrada
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    // Realiza contas do DCT
    for (int l = 0; l < n; l++){
        for (int k = 0; k < n; k++){
            double soma = 0.000;
            // itera para o somatório da matriz
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    soma = soma + matriz[x][y] * cos((2 * x + 1) * l * pi / (2 * n)) * cos((2 * y + 1) * k * pi / (2 * n));
                }  
            }
            // Verifica a Lei de formação do alpha(i) e do alpha(j)
            if (l == 0){
                alpha_i = 1.0 / sqrt(n);
            } 
            else alpha_i = sqrt(2.0 / n);

            if (k == 0){
                alpha_j = 1.0 / sqrt(n);
            } 
            else alpha_j = sqrt(2.0 / n);

            // Faz o cálculo final de cada item da matriz, considerando seu respectivo alpha(i) ou alpha(j)
            final[l][k] = alpha_i * alpha_j * soma;
        }
    }    
    // Imprime saída
    for (int o = 0; o < n; o++) {
        for (int p = 0; p < n; p++) {
            // o 9.3 na mascara do printf serve para realizar o espaço(9) entre os itens da matriz, com 3 casas decimais
            printf("%9.3f ", final[o][p]);
        }
        printf("\n");
    }
            
    return 0;
}