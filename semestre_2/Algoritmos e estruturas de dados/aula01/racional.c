#include "racional.h"

#include <stdio.h>
#include <stdlib.h>

struct racional {
    int num;
    int den;
};

void print_num(RACIONAL *r){
    printf("numerador: %d\n", r->num);
}

RACIONAL* criar(int num, int den) {
    if (den == 0) {
        return NULL;
    }
    RACIONAL* rac;
    if ((rac = (RACIONAL*)calloc(1, sizeof(RACIONAL))) == NULL) {
        exit(1);
    }
    rac->num = num;
    rac->den = den;
    return rac;
}

void apagar(RACIONAL* rac) {
    if (rac != NULL) {
        free(rac); //free = deixa a área da heap disponível para uso (não mexe no valor de rac(ponteiro))
        //rac = NULL
    }
}

RACIONAL* adicao(RACIONAL* a, RACIONAL* b) {
    RACIONAL* res;
    res = criar(0, 1);

    res->den = a->den * b->den;
    res->num = a->den * b->num + b->den * a->num;

    return res;
}

RACIONAL* multiplicacao(RACIONAL* a, RACIONAL* b) {
    RACIONAL* res;

    res = criar(0, 1);

    res->den = a->den * b->den;
    res->num = a->num * b->num;
    return res; //retornando res, que é o endereço na heap para o valor da multiplicação.
}

void imprimir(RACIONAL* rac) {
        printf("novo racional: %d/%d\n", rac->num, rac->den);
}
