#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

typedef struct _no NO;

struct _no{
    ITEM *item;
    NO *proximo;
};

struct lista_{
    NO *inicio;
    NO *fim; 
    int tamanho;
    bool ordenada;
};


LISTA *lista_criar(bool ordenada){
    LISTA *l;
    l = (LISTA *) malloc(sizeof(LISTA));

    if(l){
        l->inicio = NULL;
        l->fim = NULL;
        l->tamanho = 0;
        l->ordenada = ordenada;
    }
    return l;
}

// função auxiliar (nao esta disponivel para o usuario)
bool lista_inserir_fim(LISTA *lista, ITEM *item){
    NO *p;
    p = (NO *) malloc(sizeof(NO));
    if(p){
        p->item = item;
        p->proximo = NULL;

        if(lista->tamanho == 0){
            lista->inicio = p;
        }
        else{
            lista->fim->proximo = p;
        }
        lista->fim = p;
        lista->tamanho++;
        return true;
    }
    return false;
}

bool lista_inserir(LISTA *lista, ITEM *item){
    bool x;
    if(lista != NULL && !lista_cheia(lista)){
        if(lista->ordenada){
            ;
        }
        else{
            x = lista_inserir_fim(lista, item);
            return x;
        }
    }    

}


bool lista_cheia(LISTA *lista){
    return false;
}

ITEM *lista_remover(LISTA *lista, int chave){
    NO *p; //índice que indica quem eu quero remover
    NO *a = NULL; //auxiliar

    if (lista != NULL){
        p = lista->inicio;
        while(p != NULL && item_get_chave(p->item) != chave){
            a = p;
            p = p->proximo;
        }
        if(p != NULL){
            if(lista->inicio == p){ //Caso seja o primeiro item a ser removido
                lista->inicio = p->proximo;
            }
            else{ //Caso seja um item intermediário a ser removido
                a->proximo = p->proximo;
            }
            if(lista->fim == p){ //Caso seja o ultimo item a ser removido
                lista->fim = a;
            }
            p->proximo = NULL; 
            ITEM *it = p->item;
            free(p);
            lista->tamanho--;
            return it;
        }
    }
    return NULL;
}

ITEM *lista_busca_n_ordenada(LISTA *lista, int chave){
    NO *p;
    if (lista != NULL){
        p = lista->inicio;
        while(p != NULL){
            if (item_get_chave(p->item) == chave){
                return (p->item);
            }
            p = p->proximo;
        }
    }
    return NULL;
}

ITEM *lista_busca_ordenada(LISTA *lista, int chave){
    NO *p;
    
    if(lista != NULL){
        p = lista->inicio;
        while(p != NULL && (item_get_chave(p->item) < chave)){
            p = p->proximo;
        }
        if(p == NULL || (item_get_chave(p->item) > chave)){
            return NULL;
        }
        else{
            return p->item;
        }
    }
    return NULL;
}

ITEM *lista_busca_rec(NO *n, int chave){
    if(n == NULL){
        return(NULL);
    }
    if(item_get_chave(n->item) == chave){
        return (n->item);
    }
    return(lista_busca_rec(n->proximo, chave));

}


ITEM *lista_busca(LISTA *lista, int chave){
    ITEM *it;
    if (lista != NULL){
        if (!lista->ordenada){
            it = lista_busca_n_ordenada(lista, chave);
        }
        else{
            it = lista_busca_ordenada(lista, chave);
        }
        return it;
    }
}

bool lista_apagar(LISTA **lista){
    
}