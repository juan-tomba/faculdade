// dado um nó T, se o elemento inserido > T, vai pra direita, caso contrário, é inserido na esquerda
// só muda a inserção
#define FILHO_ESQ 0;
#define FILHO_DIR 1;
typedef struct no_ NO;
typedef struct ABB_ ABB;
struct no_{
    ITEM *it;
    NO *esq;
    NO *dir;
};

struct ABB_{
    NO *raiz;
    int profundidade;
};

// versão por inferência
NO* abb_inserir_no(NO *r, NO *novo){
    if (r == NULL){
        r = novo;
    } 
    else{
        if (item_get_chave(r->it) > item_get_chave(novo->it)){
            r->esq = abb_inserir(r->esq, NO *novo);
        }
        else r->dir = abb_inserir(r->dir, NO *novo);
    }
    return (r);
}

bool abb_inserir(ABB *T, ITEM *item){
    NO *novo_no;
    if(T == NULL){
        return false;
    }

    novo_no = abb_cria_no(item);
    if(novo_no != NULL){
        T->raiz = abb_inserir_no(T->raiz, novo_no);
        return true;
    }
    return false;
}

ITEM *abb_busca2(NO *raiz, int chave){
    if(raiz == NULL)
        return NULL;
    if(chave == item_get_chave(raiz->item))
        return (raiz->item);
        
    if(chave < item_get_chave(raiz->item))
        return (abb_busca2(raiz->esq, chave));
    else
        return (abb_busca2(raiz->dir, chave));
}

ITEM *abb_busca(ABB *T, int chave){
    return(abb_busca2(T->raiz, chave));
}