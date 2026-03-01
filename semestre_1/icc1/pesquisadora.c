#include <stdio.h>

int main() {
    FILE *arquivo;
    char caractere;
    char nome_arquivo[100];
    int contador = 0;
    scanf("%s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "r");
    while ((caractere = fgetc(arquivo)) != EOF) {
        contador++;
    }

    fclose(arquivo);
    printf("%d\n", contador);

    return 0;
}
