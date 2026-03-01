typedef struct arv_bin AB;
typedef struct No NO;
struct No {
    ITEM *item;
    NO *esq;
    NO *dir;
};
struct arv_bin {
    NO *raiz;
    int profundidade;
};


AB *ab_criar(void) {
    AB *r = (AB *) malloc(sizeof(AB));
    if (r != NULL) {
        r->raiz = NULL;
        r->profundidade = -1;
    }
    return (r);
}

void pre(NO *r){
    if(r != NULL){
        item_imprimir(r->item);
        pre(r->esq);
        pre(r->dir);
    }
}

void em(NO *r){
    if(r != NULL){
        em(r->esq);
        item_imprimir(r->item);
        em(r->dir);
    }
}

void pos(NO *r){
    if(r != NULL){
        pos(r->esq);
        pos(r->dir);
        item_imprimir(r->item);
    }
}

// #define FILHO_ESQ 0 #define FILHO_DIR 1
void ab_inserir_no(NO *raiz, NO *no, int lado, int chave_pai) {
    if (raiz != NULL) {
        ab_inserir_no(raiz->esq, no, lado, chave_pai);
        ab_inserir_no(raiz->dir, no, lado, chave_pai);
        if (chave_pai == item_get_chave(raiz->item)){
            if (lado == FILHO_ESQ)
                raiz→esq = no;
            else if (lado == FILHO_DIR)
                raiz→dir = no;
        }
    }
    return;
}


bool ab_inserir(AB *T, ITEM *item, int lado, int chave_pai){
    if (T->raiz == null){
        return((T->raiz = ab_cria_no(item)) != NULL);
    }
    else{
        NO *novo_no = ab_cria_no(item);
        if(novo_no != NULL){
            ab_inserir_no(T->raiz, novo_no, lado, chave_pai);
            return(true);
        }
        return(false);
    }

}

int profundidade(NO *r){
    if (r == NULL) return -1;
    int e = profundidade(r->esq);
    int d = profundidade(r->dir);
    if(e > d){
        return (e + 1);
    }
    else return (d + 1)

}