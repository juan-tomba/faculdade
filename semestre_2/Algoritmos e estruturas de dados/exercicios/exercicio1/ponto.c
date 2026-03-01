#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
// cria a struct ponto_
struct ponto_{
    float px;
    float py;
};
// cria o ponto recebendo as coordenadas e retorna o endereço armazenado em pont
PONTO *ponto_criar(float x, float y){
    PONTO *pont = (PONTO*)calloc(1, sizeof(PONTO));
    pont->px = x;
    pont->py = y;

    return pont;
}
// "apaga" o ponto, liberando a memória da heap nos endereços armazenados em p
void ponto_apagar(PONTO *p){
    if (p != NULL) {
        free(p); 
    }
}
// função para alterar as coordenadas do ponto p
bool ponto_set(PONTO *p, float x, float y){
    if (p != NULL){
        p->px = x;
        p->py = y;
        return true;
    }
    return false;
}
// função auxiliar para conseguir a coordenada x do ponto p, para ser utilizada em circulo.c e não quebrar o information hiding
float busca_x(PONTO *p) {
    if (p != NULL) {
        return p->px;
    }
    return 0;
}
// função auxiliar para conseguir a coordenada y do ponto p, para ser utilizada em circulo.c e não quebrar o information hiding
float busca_y(PONTO *p) {
    if (p != NULL) {
        return p->py;
    }
    return 0;
}