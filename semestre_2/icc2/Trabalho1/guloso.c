#include <stdio.h>

// struct item para organização dos valores de cada item (nome, peso, valor e razao)
typedef struct {
    char nome[50];
    int peso;
    int valor;
    double razao;
} Item;

// função auxiliar para a troca de itens no quicksort
void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// quick sort decrescente, que organiza os itens de acordo com sua razao de: (valor / peso)
void quicksort(Item v[], int inicio, int fim) {
    int i = inicio, j = fim;
    double pivo = v[(inicio + fim) / 2].razao;

    while (i <= j) {
        while (v[i].razao > pivo) i++;  
        while (v[j].razao < pivo) j--;
        if (i <= j) {
            swap(&v[i], &v[j]);
            i++;
            j--;
        }
    }

    if (inicio < j) quicksort(v, inicio, j);
    if (i < fim) quicksort(v, i, fim);
}

int main() {
    printf("Esse programa resolve o problema da mochila (knapsack problem) atraves do metodo guloso.\n\n");
    
    int n, capacidade;
    printf("Informe o peso maximo suportado pela mochila: ");
    scanf("%d", &capacidade);

    printf("Digite quantos itens serao avaliados: ");
    scanf("%d", &n);

    Item itens[n];
    // leitura dos itens da mochila
    printf("Digite os %d itens no formato\n\"nome\" \"peso\" \"valor\":\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%s %d %d", itens[i].nome, &itens[i].peso, &itens[i].valor) != 3) {
            printf("Entrada invalida.\n");
            return 1;
        }
        itens[i].razao = (double) itens[i].valor / itens[i].peso;
    }

    quicksort(itens, 0, n - 1);

    int peso_atual = 0;
    int valor_total = 0;

    printf("\n--- Itens Escolhidos pela Estrategia Gulosa ---\n");
    printf("Itens na mochila:\n");

    // vai inserindo os itens com maior razão valor/peso, até não ter espaço na mochila para o próximo
    for (int i = 0; i < n; i++) {
        if (peso_atual + itens[i].peso <= capacidade) {
            peso_atual += itens[i].peso;
            valor_total += itens[i].valor;
            printf("  - %s (Peso: %d, Valor: %d, Razao: %.2f)\n", itens[i].nome, itens[i].peso, itens[i].valor, itens[i].razao);
        }
    }

    if (valor_total == 0){
        printf("\nNenhuma combinacao de itens coube na mochila.\n");
    } else {
        printf("\nPeso total na mochila: %d (Capacidade: %d)\n", peso_atual, capacidade);
        printf("Valor total na mochila: %d\n", valor_total);
    }

    return 0;
}
