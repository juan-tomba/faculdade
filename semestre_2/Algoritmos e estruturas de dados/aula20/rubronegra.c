NO_T* rodar_dir(NO_T *c){
    // rotação
    NO_T *b = c->esq;
    c->esq = b->dir;
    b->dir = c;

    //troca de cores
    b->cor = c->cor;
    c->cor = 1;

    return b;
}

NO_T* rodar_esq(NO_T *c){
    // rotação
    NO_T *b = c->dir;
    c->dir = b->esq;
    b->esq = c;

    //troca de cores
    b->cor = c->cor;
    c->cor = 1;

    return b;
}