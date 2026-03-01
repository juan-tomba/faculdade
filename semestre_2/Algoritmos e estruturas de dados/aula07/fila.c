#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

FILA *fila_criar(void){
    FILA *f;
    f = (FILA *) malloc(sizeof(FILA));
    if (f != NULL){
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return (f);
}

bool fila_inserir(FILA *fila, ITEM *item){
    if (fila != NULL && !fila_cheia(fila)){
        NO *n = (NO*) malloc(sizeof(NO));
        n->item = item;
        n->proximo = NULL;

        if (fila->inicio == NULL)
            fila->inicio = n;
        else
            fila->fim->proximo = n;
        fila->fim = n;
        fila->tamanho++;
        return (true);
    }
    return (false);
}

ITEM *fila_remover(FILA *fila){
    if (fila != NULL && !fila_vazia(fila)){
        NO *p;
        p = fila->inicio;

        ITEM *it = p->item;

        fila->inicio = p->proximo;
        fila->tamanho--;

        if(fila->tamanho == 0)
            fila->fim = NULL;

        free(p);
        p = NULL;
        return(it);
    }
    else{
        return (NULL);
    }
}

bool fila_vazia(FILA *fila){

}

bool fila_cheia(FILA *fila){

}