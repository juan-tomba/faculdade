#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[10];
    char cidade[50];
} Pessoa;

int main() {
    Pessoa pessoas[200];
    int total = 0;
    char comando[100];
    char nomeArquivo[50];
    scanf("%s", nomeArquivo);
    getchar(); 

    FILE *arq = fopen(nomeArquivo, "r");
    if (arq != NULL) {
        while (fgets(comando, sizeof(comando), arq) != NULL) {
            sscanf(comando, " %[^,], %[^,], %[^\n]", pessoas[total].nome, pessoas[total].telefone, pessoas[total].cidade);
            total++;
        }
        fclose(arq);
    }

    while (fgets(comando, sizeof(comando), stdin) != NULL) {
        if (strncmp(comando, "ADD", 3) == 0) {
            sscanf(comando + 4, " %[^,], %[^,], %[^\n]", pessoas[total].nome, pessoas[total].telefone, pessoas[total].cidade);
            total++;
        } else if (strncmp(comando, "DEL", 3) == 0) {
            int idx;
            sscanf(comando + 4, "%d", &idx);
            if (idx >= 0 && idx < total) {
                for (int i = idx; i < total - 1; i++) {
                    pessoas[i] = pessoas[i + 1];
                }
                total--;
            }
        }
    }

    arq = fopen(nomeArquivo, "w");
    for (int i = 0; i < total; i++) {
        fprintf(arq, "%s, %s, %s\n", pessoas[i].nome, pessoas[i].telefone, pessoas[i].cidade);
    }
    fclose(arq);

    for (int i = 0; i < total; i++) {
        printf("%s, %s, %s\n", pessoas[i].nome, pessoas[i].telefone, pessoas[i].cidade);
    }

    return 0;
}