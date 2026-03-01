#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  no{
    int chave;
    char valor[10];
} no_t;

void swap(no_t *n1, no_t *n2){
    no_t aux;

    /*aux->chave = n1->chave;
    n1->chave = n2->chave;
    n2->chave = aux->chave;

    strcpy(aux->valor, n1->valor);
    strcpy(n1->valor, n2->valor);
    strcpy(n2->valor, aux->valor);*/

    memcpy(&aux, n1, sizeof(no_t));
    memcpy(n1, n2, sizeof(no_t));
    memcpy(n2, &aux, sizeof(no_t));
}

void swap_pointer(no_t **n1, no_t **n2){
    no_t *aux;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;

}

int main(){
    no_t n1, n2;
    n1.chave = 1;
    strcpy(n1.valor, "aaa");
    n2.chave = 2;
    strcpy(n2.valor, "bbb");

    swap(&n1, &n2);

    printf("%d %s\n", n1.chave, n1.valor);
    printf("%d %s\n", n2.chave, n2.valor);

    no_t *p1, *p2;
    p1 = (no_t *)malloc(sizeof(no_t));
    p2 = (no_t *)malloc(sizeof(no_t));
    p1->chave = 1;
    strcpy(p1->valor, "aaa");
    p2->chave = 2;
    strcpy(p2->valor, "bbb");

    swap_pointer(&p1, &p2);

    printf("\n");
    printf("%d %s\n", p1->chave, p1->valor);
    printf("%d %s\n", p2->chave, p2->valor);

    return 0;
}