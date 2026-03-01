#include <stdio.h>

#define MAX_ITENS 100
#define MAX_PESO 1000

typedef struct {
    char nome[50];
    int peso;
    int valor;
} Item;

int tabela[MAX_ITENS + 1][MAX_PESO + 1]; // tabela para armazenar os valores máximos

// função recursiva
int mochilaRec(int i, int W, Item itens[]) {
    // caso base: sem itens ou capacidade zero
    if (i == 0 || W == 0)
        return 0;

    // se já foi calculado, retorna o valor armazenado
    if (tabela[i][W] != -1)
        return tabela[i][W];

    // verifica se o peso do item atual for maior que a capacidade restante
    if (itens[i - 1].peso > W)
        return tabela[i][W] = mochilaRec(i - 1, W, itens);


    // verifica se ele não pega o item (semItem) ou se pega o item (comItem)
    int semItem = mochilaRec(i - 1, W, itens);
    int comItem = itens[i - 1].valor + mochilaRec(i - 1, W - itens[i - 1].peso, itens);

    // escolhe o maior valor entre os dois
    tabela[i][W] = (comItem > semItem) ? comItem : semItem;
    return tabela[i][W];
}

// função para printar os itens escolhidos
void printarItensEscolhidos(int n, int W, Item itens[]) {
    printf("\nItens escolhidos:\n");
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        // se o valor atual é diferente do de cima, o item foi escolhido
        if (tabela[i][w] != tabela[i - 1][w]) {
            printf(" - %s (Peso: %d, Valor: %d)\n", itens[i - 1].nome, itens[i - 1].peso, itens[i - 1].valor);
            // atualiza o peso restante da mochila
            w -= itens[i - 1].peso;
        }
    }
}

int main() {
    int n, capacidade;
    printf("Esse programa resolve o problema da mochila (knapsack problem) atraves da programação dinâmica.\n\n");

    printf("Informe o peso maximo suportado pela mochila: ");
    scanf("%d", &capacidade);

    printf("Digite quantos itens serao avaliados: ");
    scanf("%d", &n);

    Item itens[n];

    printf("Digite os %d itens no formato\n\"nome\" \"peso\" \"valor\":\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", itens[i].nome, &itens[i].peso, &itens[i].valor);
    }

    // inicializa tabela com -1
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= capacidade; j++)
            tabela[i][j] = -1;

    int resultado = mochilaRec(n, capacidade, itens);

    printf("\nValor maximo obtido: %d\n", resultado);

    
    printf("\n--- Itens Escolhidos pela Programação Dinâmica ---\n");
    printf("Itens na mochila:\n");
    printarItensEscolhidos(n, capacidade, itens);

    return 0;
}
