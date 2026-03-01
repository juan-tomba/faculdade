#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "Pilha.h"

// Verifica se o caractere é a abertura de uma chave
bool abre(char c) {
    return (c == '(' || c == '[' || c == '{');
}

// Verifica se o caractere é o fechamento de uma chave
bool fecha(char c) {
    return (c == ')' || c == ']' || c == '}');
}

// Verifica o par
bool par(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

bool balanceada(char *sequencia) {
    PILHA *p = pilha_criar();

    for (int i = 0; sequencia[i] != '\0'; i++) {
        char c = sequencia[i];

        if (abre(c)) {
            ITEM *novo = item_criar(c); 
            pilha_empilhar(p, novo);
        } 
        else if (fecha(c)) {
            if (pilha_vazia(p)) {
                pilha_apagar(&p);
                return false;
            }
            ITEM *topo = pilha_desempilhar(p);
            char abre = (char) item_get_chave(topo);
            item_apagar(&topo);

            if (!par(abre, c)) {
                pilha_apagar(&p);
                return false;
            }
        }
    }

    bool verifica = pilha_vazia(p);
    pilha_apagar(&p);
    return verifica;
}
