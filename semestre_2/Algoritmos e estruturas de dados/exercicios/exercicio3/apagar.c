#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct _no NO;

struct _no{
    ITEM *item;
    NO *proximo;
};

struct fila_{
    NO *inicio;
    NO *fim;
    int tamanho;
};

void recursao(NO *elem){
    if(elem->proximo == NULL){
        free(elem);
        return;
    }

    NO* aux = elem->proximo;
    free(elem);
    recursao(aux);

}

void fila_apagar(FILA **f) {
    if(fila_vazia(*f) || f == NULL){
        return;
    }
    NO* aux = (*f)->inicio;
    recursao(aux);

    (*f)->inicio = NULL;
    (*f)->fim = NULL;
    free(*f);
    *f = NULL;
    

}