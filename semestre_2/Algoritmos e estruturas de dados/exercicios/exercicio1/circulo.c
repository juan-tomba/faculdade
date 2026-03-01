#include "circulo.h"
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
// define a struct circulo_
struct circulo_{
    float x;
    float y;
    float raio;
};
// inicializa CIRCULO *circ, que recebe as coordenadas em p (utilizando busca_x e busca_y para buscar valores de PONTO *p) e o raio
CIRCULO *circulo_criar(PONTO *p, float raio){
    CIRCULO *circ = (CIRCULO*)calloc(1, sizeof(CIRCULO));
    circ->x = busca_x(p);
    circ->y = busca_y(p);
    circ->raio = raio;

    return circ;

}
// "apaga" o circulo, liberando a memória da heap nos endereços armazenados em circ
void circulo_apagar (CIRCULO* circ){
    if (circ != NULL) {
        free(circ); 
    }
}
// calcula a área de circ, utilizando area= raio * raio * PI
float circulo_area (CIRCULO* circ){
    float area;
    area = circ->raio * circ->raio * 3.1415;

    return area;
}
// função para calcular a distancia entre 2 pontos, conforme o enunciado
float distancia(PONTO* p, CIRCULO* r){
    float x2 = busca_x(p), x1 = r->x, y2 = busca_y(p), y1 = r->y;
    float term1 = pow((x2 - x1), 2);
    float term2 = pow((y2 - y1), 2);
    float resul = sqrt(term1 + term2);

    return resul;
}