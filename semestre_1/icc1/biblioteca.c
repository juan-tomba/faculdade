#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *titulo;
    char *autor;
    int ano;
    int quantidade;
} Livro;

int iguais(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}

int main() {
    int n, total = 0;
    scanf("%d\n", &n);

    Livro *catalogo = malloc(n * sizeof(Livro));

    for (int i = 0; i < n; i++) {
        char titulo[101], autor[51];
        int ano;

        scanf(" %100[^,], %50[^,], %d\n", titulo, autor, &ano);

        int encontrado = 0;
        for (int j = 0; j < total; j++) {
            if (iguais(catalogo[j].titulo, titulo) && iguais(catalogo[j].autor, autor) && catalogo[j].ano == ano) {
                catalogo[j].quantidade++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            catalogo[total].titulo = malloc(strlen(titulo) + 1);
            for (int k = 0; titulo[k] != '\0'; k++){
                catalogo[total].titulo[k] = titulo[k];
            }
            catalogo[total].titulo[strlen(titulo)] = '\0';

            catalogo[total].autor = malloc(strlen(autor) + 1);
            for (int k = 0; autor[k] != '\0'; k++){
                catalogo[total].autor[k] = autor[k];
            }
            catalogo[total].autor[strlen(autor)] = '\0';

            catalogo[total].ano = ano;
            catalogo[total].quantidade = 1;
            total++;
        }
    }

    printf("Catalogo de Livros:\n");
    for (int i = 0; i < (total - 1); i++) {
        printf("Livro %d:\n", i + 1);
        printf("Titulo: %s\n", catalogo[i].titulo);
        printf("Autor: %s\n", catalogo[i].autor);
        printf("Ano: %d\n", catalogo[i].ano);
        printf("Quantidade: %d\n\n", catalogo[i].quantidade);
    }
        printf("Livro %d:\n", total);
        printf("Titulo: %s\n", catalogo[(total - 1)].titulo);
        printf("Autor: %s\n", catalogo[(total - 1)].autor);
        printf("Ano: %d\n", catalogo[(total - 1)].ano);
        printf("Quantidade: %d\n", catalogo[(total - 1)].quantidade);

    for (int i = 0; i < total; i++) {
        free(catalogo[i].titulo);
        free(catalogo[i].autor);
    }
    free(catalogo);

    return 0;
}
