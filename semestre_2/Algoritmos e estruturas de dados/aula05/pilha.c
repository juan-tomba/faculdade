#include <stdio.h>
#include <stdlib.h>
typedef struct ITEM ITEM;

typedef struct no {
    ITEM* item;
    NO* anterior;
}NO;
typedef struct pilha {
    NO* topo;
    int tamanho;
}PILHA;

void pilha_apagar(PILHA **pilha){
    NO *aux;
    if (*pilha != NULL && !pilha_vazia(*pilha)){
        while ((*pilha)->topo != NULL){
            aux = (*pilha)->topo;
            (*pilha)->topo = aux->anterior;
            item_apagar(&aux->item); aux->anterior = NULL;
            free(aux); aux = NULL;
        }
        free(*pilha); (*pilha) = NULL;
    }

}


int main(){
    PILHA *p;
    p = pilha_criar();
    pilha_apagar(&p);
}