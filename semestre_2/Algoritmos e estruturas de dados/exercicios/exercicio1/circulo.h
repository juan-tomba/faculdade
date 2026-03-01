#ifndef CIRCULO_H
    #define CIRCULO_H

    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ);
    float distancia(PONTO* p, CIRCULO* r);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif


