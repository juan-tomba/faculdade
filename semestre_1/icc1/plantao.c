#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nome;
    int nusp;
    char* assunto;
} geral;

int main(){
    int n, m, i;
    scanf("%d", &n);
    geral *blocoA = malloc(n * sizeof(geral));
    for (i = 0; i < n; i++){
        blocoA[i].nome = malloc(100 * sizeof(char));
        blocoA[i].assunto = malloc(100 * sizeof(char));

        scanf(" %[^\n]s", blocoA[i].nome);
        scanf("%d", &blocoA[i].nusp);
        scanf(" %[^\n]s", blocoA[i].assunto);
    }

    scanf("%d", &m);
    blocoA = realloc(blocoA, (n + m) * sizeof(geral));
    for (; i < (m + n); i++){
        blocoA[i].nome = malloc(100 * sizeof(char));
        blocoA[i].assunto = malloc(100 * sizeof(char));

        scanf(" %[^\n]s", blocoA[i].nome);
        scanf("%d", &blocoA[i].nusp); 
        scanf(" %[^\n]s", blocoA[i].assunto);
    }

    for(int j = 0; j < (n + m); j++){
        printf("Discente %d:\n", (j + 1));
        printf("Nome: %s\n", blocoA[j].nome);
        printf("Número USP: %d\n", blocoA[j].nusp);
        printf("Assunto: %s\n", blocoA[j].assunto);
        printf("\n");
    }
    for (int i = 0; i < (n + m); i++) {
        free(blocoA[i].nome);
        free(blocoA[i].assunto);
    }
    free(blocoA);

    return 0;
}