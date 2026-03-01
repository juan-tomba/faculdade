/*
Resumo: Implementação de Pilhas
--------------------------------
- Duas formas de implementação:
  1) Sequencial (com arrays fixos)
  2) Dinâmica Encadeada (com ponteiros e nós)

A seguir, mostramos as duas versões com comentários explicativos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100   // tamanho máximo da pilha na versão sequencial

/***********************
 * IMPLEMENTAÇÃO SEQUENCIAL
 ***********************/

// Estrutura da pilha (sequencial)
// - Vetor fixo de ponteiros para ITEM
// - "tamanho" indica quantos elementos existem (e a posição do topo)
typedef struct {
    int item[TAM];   // aqui usamos int só para simplificar
    int tamanho;     // controla o topo
} PILHA_SEQ;

// Criar pilha
PILHA_SEQ* pilha_seq_criar() {
    PILHA_SEQ* pilha = (PILHA_SEQ*) malloc(sizeof(PILHA_SEQ));
    if (pilha != NULL) pilha->tamanho = 0;
    return pilha;
}

// Verifica se está vazia
bool pilha_seq_vazia(PILHA_SEQ* pilha) {
    return (pilha->tamanho == 0);
}

// Verifica se está cheia
bool pilha_seq_cheia(PILHA_SEQ* pilha) {
    return (pilha->tamanho == TAM);
}

// Empilhar (push) → coloca item no topo
bool pilha_seq_empilhar(PILHA_SEQ* pilha, int valor) {
    if (!pilha_seq_cheia(pilha)) {
        pilha->item[pilha->tamanho] = valor;
        pilha->tamanho++;
        return true;
    }
    return false; // pilha cheia
}

// Desempilhar (pop) → remove e retorna item do topo
int pilha_seq_desempilhar(PILHA_SEQ* pilha) {
    if (!pilha_seq_vazia(pilha)) {
        pilha->tamanho--;
        return pilha->item[pilha->tamanho];
    }
    return -1; // erro (pilha vazia)
}

// Mostrar pilha
void pilha_seq_print(PILHA_SEQ* pilha) {
    printf("Pilha Sequencial: [ ");
    for (int i = 0; i < pilha->tamanho; i++) {
        printf("%d ", pilha->item[i]);
    }
    printf("]\n");
}


/***********************
 * IMPLEMENTAÇÃO DINÂMICA ENCADEADA
 ***********************/

// Estrutura de nó encadeado
typedef struct no {
    int item;           // valor armazenado
    struct no* anterior; // aponta para o nó anterior
} NO;

// Estrutura da pilha encadeada
typedef struct {
    NO* topo;   // ponteiro para o nó do topo
    int tamanho;
} PILHA_ENC;

// Criar pilha
PILHA_ENC* pilha_enc_criar() {
    PILHA_ENC* pilha = (PILHA_ENC*) malloc(sizeof(PILHA_ENC));
    if (pilha != NULL) {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

// Verifica se está vazia
bool pilha_enc_vazia(PILHA_ENC* pilha) {
    return (pilha->tamanho == 0);
}

// Empilhar → cria nó novo e coloca no topo
bool pilha_enc_empilhar(PILHA_ENC* pilha, int valor) {
    NO* pnovo = (NO*) malloc(sizeof(NO));
    if (pnovo != NULL) {
        pnovo->item = valor;
        pnovo->anterior = pilha->topo;
        pilha->topo = pnovo;
        pilha->tamanho++;
        return true;
    }
    return false; // erro de alocação
}

// Desempilhar → remove nó do topo e retorna valor
int pilha_enc_desempilhar(PILHA_ENC* pilha) {
    if (!pilha_enc_vazia(pilha)) {
        NO* pno = pilha->topo;
        int valor = pno->item;
        pilha->topo = pno->anterior; // move topo
        free(pno);                   // libera memória
        pilha->tamanho--;
        return valor;
    }
    return -1; // erro (pilha vazia)
}

// Mostrar pilha (do topo até a base)
void pilha_enc_print(PILHA_ENC* pilha) {
    NO* aux = pilha->topo;
    printf("Pilha Encadeada: [ ");
    while (aux != NULL) {
        printf("%d ", aux->item);
        aux = aux->anterior;
    }
    printf("]\n");
}


/***********************
 * TESTE DAS DUAS PILHAS
 ***********************/
int main() {
    // Teste da pilha sequencial
    PILHA_SEQ* ps = pilha_seq_criar();
    pilha_seq_empilhar(ps, 10);
    pilha_seq_empilhar(ps, 20);
    pilha_seq_empilhar(ps, 30);
    pilha_seq_print(ps);
    printf("Desempilhou (seq): %d\n", pilha_seq_desempilhar(ps));
    pilha_seq_print(ps);

    // Teste da pilha encadeada
    PILHA_ENC* pe = pilha_enc_criar();
    pilha_enc_empilhar(pe, 100);
    pilha_enc_empilhar(pe, 200);
    pilha_enc_empilhar(pe, 300);
    pilha_enc_print(pe);
    printf("Desempilhou (enc): %d\n", pilha_enc_desempilhar(pe));
    pilha_enc_print(pe);

    return 0;
}

/*
Resumo Final:
-------------
- Sequencial (array): simples, mas precisa de tamanho fixo (TAM).
- Dinâmica Encadeada (ponteiros): mais flexível, cresce dinamicamente,
  mas usa malloc/free e ponteiros.

Ambas possuem operações: criar, empilhar, desempilhar, verificar vazia.
*/
