/*
Resumo: Implementação de Pilhas em C
-------------------------------------
Aqui estão as operações principais tanto para a
implementação SEQUENCIAL (array fixo) quanto
para a DINÂMICA ENCADEADA (ponteiros e nós).

Cada trecho vem comentado para facilitar o estudo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100   // tamanho máximo da pilha na versão sequencial


/***********************
 * IMPLEMENTAÇÃO SEQUENCIAL
 ***********************/

// Estrutura da pilha sequencial
typedef struct {
    int item[TAM];   // vetor fixo
    int tamanho;     // controla o topo
} PILHA_SEQ;

// Criar pilha
PILHA_SEQ* pilha_seq_criar() {
    PILHA_SEQ* pilha = (PILHA_SEQ*) malloc(sizeof(PILHA_SEQ));
    if (pilha != NULL) pilha->tamanho = 0; // inicia vazia
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

// Empilhar (push)
bool pilha_seq_empilhar(PILHA_SEQ* pilha, int valor) {
    if (!pilha_seq_cheia(pilha)) {
        pilha->item[pilha->tamanho] = valor; // coloca no topo
        pilha->tamanho++;
        return true;
    }
    return false; // pilha cheia
}

// Desempilhar (pop)
int pilha_seq_desempilhar(PILHA_SEQ* pilha) {
    if (!pilha_seq_vazia(pilha)) {
        pilha->tamanho--;              // reduz tamanho
        return pilha->item[pilha->tamanho]; // retorna valor removido
    }
    return -1; // erro (pilha vazia)
}


/***********************
 * IMPLEMENTAÇÃO DINÂMICA ENCADEADA
 ***********************/

// Estrutura do nó encadeado
typedef struct no {
    int item;            // valor armazenado
    struct no* anterior; // aponta para o nó abaixo
} NO;

// Estrutura da pilha encadeada
typedef struct {
    NO* topo;    // ponteiro para o nó do topo
    int tamanho; // contador de elementos
} PILHA_ENC;

// Criar pilha
PILHA_ENC* pilha_enc_criar() {
    PILHA_ENC* pilha = (PILHA_ENC*) malloc(sizeof(PILHA_ENC));
    if (pilha != NULL) {
        pilha->topo = NULL;   // começa sem elementos
        pilha->tamanho = 0;
    }
    return pilha;
}

// Verifica se está vazia
bool pilha_enc_vazia(PILHA_ENC* pilha) {
    return (pilha->tamanho == 0);
}

// Empilhar (push)
bool pilha_enc_empilhar(PILHA_ENC* pilha, int valor) {
    NO* pnovo = (NO*) malloc(sizeof(NO)); // cria novo nó
    if (pnovo != NULL) {
        pnovo->item = valor;
        pnovo->anterior = pilha->topo; // liga ao antigo topo
        pilha->topo = pnovo;           // atualiza topo
        pilha->tamanho++;
        return true;
    }
    return false; // erro de alocação
}

// Desempilhar (pop)
int pilha_enc_desempilhar(PILHA_ENC* pilha) {
    if (!pilha_enc_vazia(pilha)) {
        NO* pno = pilha->topo;       // nó a ser removido
        int valor = pno->item;       // guarda valor
        pilha->topo = pno->anterior; // atualiza topo
        free(pno);                   // libera memória
        pilha->tamanho--;
        return valor;
    }
    return -1; // erro (pilha vazia)
}


/*
Resumo Final:
-------------
- Sequencial (array fixo):
    + Simples, acesso direto.
    - Limite de TAM definido em compilação.

- Dinâmica Encadeada (lista ligada):
    + Cresce conforme necessário, sem limite fixo.
    - Mais complexa, usa malloc/free.

Operações em ambas: criar, empilhar, desempilhar,
verificar se vazia.
*/
