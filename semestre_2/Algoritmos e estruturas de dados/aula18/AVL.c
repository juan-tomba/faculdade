#define max(a, b) ((a > b) ? a : b)
typedef struct no_ NO;
typedef struct avl AVL;
struct no_{
    ITEM *item;
    NO *fesq;
    NO *fdir;
    int altura;
};

struct avl{
    NO *raiz;
    int profundidade;
};

NO* rodar_direita(NO *A){
    NO *B = A->fesq;
    A->fesq = B->fdir;
    B->fdir = A;
    A->altura = max(avl_altura_no(A->fesq), avl_altura_no(A->fdir)) + 1;

    return B;
}

NO* rodar_esquerda_direita(NO *A){
    A->fesq = rodar_esquerda(A->FESQ);
    return (rodar_direita(A));
}