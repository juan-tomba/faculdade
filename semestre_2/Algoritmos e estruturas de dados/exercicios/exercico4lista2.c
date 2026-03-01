#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free
#include <string.h>

// Sugestão: Renomear a struct para algo mais descritivo como "Estacionamento"
typedef struct {
    char carros[10][20];
    int tamanho;
} Estacionamento;

// Sua função estaciona_carro (está correta)
int estaciona_carro(char* placa, Estacionamento* est) {
    if (est != NULL && est->tamanho < 10) {
        strcpy(est->carros[est->tamanho], placa);
        est->tamanho++;
        return 1;
    }
    return 0;
}

// Função retira_carro CORRIGIDA
int retira_carro(char* placa, Estacionamento* est) {
    if (est == NULL || est->tamanho == 0) {
        return 0; // Estacionamento não existe ou está vazio
    }

    Estacionamento* rua_aux = (Estacionamento*) malloc(sizeof(Estacionamento));
    rua_aux->tamanho = 0;
    
    int carro_encontrado = 0;

    // 1. Move os carros para a 'rua' até encontrar o alvo
    while (est->tamanho > 0) {
        // Pega o carro do topo
        char* carro_atual = est->carros[est->tamanho - 1];

        // Diminui o tamanho do estacionamento (equivalente a um pop)
        est->tamanho--;

        // Compara com a placa desejada
        if (strcmp(carro_atual, placa) == 0) {
            carro_encontrado = 1; // Encontrou! Não o colocamos na rua_aux.
            break; // Para o laço de remoção
        } else {
            // Não é o carro, move para a rua
            estaciona_carro(carro_atual, rua_aux);
        }
    }

    // 2. Devolve os carros da rua para o estacionamento
    while (rua_aux->tamanho > 0) {
        char* carro_para_devolver = rua_aux->carros[rua_aux->tamanho - 1];
        rua_aux->tamanho--; // "Pop" da rua
        
        estaciona_carro(carro_para_devolver, est); // "Push" de volta no estacionamento
    }

    // 3. Libera a memória da estrutura auxiliar
    free(rua_aux);

    return carro_encontrado;
}

void imprime_estacionamento(Estacionamento* est) {
    printf("--- ESTACIONAMENTO ---\n");
    if (est->tamanho == 0) {
        printf("Vazio\n");
    } else {
        // Imprime da entrada (índice 0) para a saída (topo)
        for (int i = 0; i < est->tamanho; i++) {
            printf("%d: %s\n", i, est->carros[i]);
        }
    }
    printf("----------------------\n\n");
}
