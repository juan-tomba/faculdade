#include <stdio.h>
#define B 17

typedef struct{
    int chave, valor;
} hash_t;

hash_t table[B]

int hash(int chave){
    return (chave % B);
}

int inserir(int chave, int valor){
    int ind = hash(chave);
    int indfake = ind;
    for(int i = 0; i < B; i++){
        if(table[indfake].chave == -1 || table[indfake].chave == -2){
            table[indfake].chave = chave;
            table[indfake].valor = valor;
            return 0;
        } else {
            indfake = (ind + i) % B;
        }
    }
    return 1; // não conseguiu inserir
}

int busca(int chave){
    int ind = hash(chave);
    int indfake = ind;
    for(int i = 0; i < B; i++){
        if(table[indfake].chave == chave){
            return table[indfake].valor
        } if(table[indfake].chave == -1) {
            return -1;
        }
        else {
            indfake = (ind + i) % B;
        }
    }
    return -1; // não conseguiu achar
}

int remover(int chave){
    int ind = hash(chave);
    int indfake = ind;
    for(int i = 0; i < B; i++){
        if(table[indfake].chave == chave){
            table[indfake].chave == -2; // removido
            return 0;
        } if(table[indfake].chave == -1) {
            return 1;
        } else {
            indfake = (ind + i) % B;
        }
    }
    return 1; // não encontrado
}

int main(){
    for(int i = 0; i < B; i++){
        table[i].chave = -1;
    }

    inserir(4, 7);
    inserir(8, 3);
    inserir(2, 9);
    inserir(1, 2);
    inserir(19, 8);
    remover(2);

    printf("%d", busca(8));

    return 0;
}