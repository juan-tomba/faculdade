#include "circulo.h"
#include "ponto.h"
#include <stdio.h>

int main(){
    float ponto_x, ponto_y, circulo_x, circulo_y, raio;
    scanf("%f %f", &ponto_x, &ponto_y);
    scanf("%f %f %f", &circulo_x, &circulo_y, &raio);

    PONTO *p = ponto_criar(ponto_x , ponto_y);
    PONTO *centro = ponto_criar(circulo_x , circulo_y);
    CIRCULO *circulo = circulo_criar(centro, raio);
    // escolhi implementar a função em circulo.c por causa da função auxiliar busca_x e busca_y, para nao ter que precisar criar outra função auxiliar e continuar com o princípio do TAD, information hiding
    float dist = distancia(p, circulo);
    if (dist < raio){
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    }
    if (dist > raio){
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    }
    if (dist == raio){
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    }

    ponto_apagar(p);
    ponto_apagar(centro);
    circulo_apagar(circulo);
    return 0;
}