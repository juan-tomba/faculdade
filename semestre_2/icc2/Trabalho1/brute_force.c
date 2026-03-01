#include <stdio.h>
#include <stdlib.h> 

// struct It para organização dos valores de cada item (nome, peso, valor e razao) 
typedef struct {
    int peso;
    int valor;
    char nome[50];
} It;

// funcao recursiva que encontra todos os subconjuntos possíveis de elementos, e escolhe o de melhor resultado
void encontrar_melhor_combinacao(
    It todos_os_itens[],   //recebe todos os itens que serão avaliados
    int n_total_itens,     //numero total de itens
    It combinacao_atual[], //combinacao atual para analisar a cada chamada da recursao
    int tam_comb_atual,    //numero de itens na combinacao atual
    int indice,            //qual o nivel atual da recursao (tamanho do subconjunto)
    int capacidade_mochila, //capacidade total da mochila
    int* maior_valor_global, //maior valor que foi encontrado pela melhor combinacao ate o momento
    It** melhor_combinacao_global, //conjunto de itens da melhor combinacao ate o momento
    int* tamanho_melhor_combinacao //numero de itens da melhor combinacao ate o momento

) {
    
    //condicao de parada: tamanho do subconjunto ser igual ao numero total de itens
    if (indice == n_total_itens) {
        int peso_atual = 0;
        int valor_atual = 0;

        //analisa a combinacao formada nessa etapa da recursao e soma os pesos e os valores dos itens que ela contem
        for (int i = 0; i < tam_comb_atual; i++) {
            peso_atual += combinacao_atual[i].peso;
            valor_atual += combinacao_atual[i].valor;
        }

        //se o peso total da combinacao atual for menor que a capacidade da mochila e o valor dos itens for maior que o melhor ate entao
        //atualiza o maior valor encontrado e passa os itens da combinacao atual para o vetor melhor combinacao
        if (peso_atual <= capacidade_mochila && valor_atual > *maior_valor_global) {
            *maior_valor_global = valor_atual;
            *tamanho_melhor_combinacao = tam_comb_atual;

            *melhor_combinacao_global = (It*) realloc(*melhor_combinacao_global, tam_comb_atual * sizeof(It));
            
            for (int i = 0; i < tam_comb_atual; i++) {
                (*melhor_combinacao_global)[i] = combinacao_atual[i];
            }
        }

        return; 
    }
    
    //Escolhe que o item nao vai entrar no conjunto, e chama a recursao para o proximo item
    encontrar_melhor_combinacao(todos_os_itens, n_total_itens, combinacao_atual, tam_comb_atual, indice + 1, capacidade_mochila, maior_valor_global, melhor_combinacao_global, tamanho_melhor_combinacao);

    //Escolhe que o item vai entrar no conjunto, e chama a recursao para o proximo item
    combinacao_atual[tam_comb_atual] = todos_os_itens[indice];
    encontrar_melhor_combinacao(todos_os_itens, n_total_itens, combinacao_atual, tam_comb_atual + 1, indice + 1, capacidade_mochila, maior_valor_global, melhor_combinacao_global, tamanho_melhor_combinacao);
}

int main() {
    //Trata a entrada dos valores de capacidade da mochila e quantidade de itens
    printf("Esse programa resolve o problema da mochila (knapsack problem) atraves da forca bruta.\n\n");
    
    int w;
    printf("Informe o peso maximo suportado pela mochila: ");
    scanf("%d", &w);

    int n;
    printf("Digite quantos itens serao avaliados: ");
    scanf("%d", &n);

    //cria vetor de itens dinamicamente
    It* itens = (It*) malloc(n * sizeof(It));
    if (itens == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    //pega as entradas do usuario
    printf("Digite os %d itens no formato\n\"nome\" \"peso\" \"valor\":\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%s %d %d", itens[i].nome, &itens[i].peso, &itens[i].valor) != 3) {
            printf("Entrada invalida.\n");
            free(itens);
            return 1;
        }
    }

    //cria a combinacao atual que sera analisada pela funcao recursiva
    It* combinacao_atual = (It*) malloc(n * sizeof(It));
    if (combinacao_atual == NULL) {
        printf("Erro de alocacao de memoria!\n");
        free(itens);
        return 1;
    }

    //inicia as variaveis da melhor combinacao
    int maior_valor_global = 0;
    It* melhor_combinacao_global = NULL;
    int tamanho_melhor_combinacao = 0;

    
    encontrar_melhor_combinacao(itens, n, combinacao_atual, 0, 0, w, &maior_valor_global, &melhor_combinacao_global, &tamanho_melhor_combinacao);

    //se encontrou uma combinacao com valor válido, retorna os itens, o valor total e o peso total dessa combinacao
    if (maior_valor_global > 0) {
        printf("\n--- Solucao Otima Encontrada ---\n");
        printf("Maior valor: %d\n", maior_valor_global);
        printf("Itens na mochila:\n");
        int peso_final = 0;
        for (int i = 0; i < tamanho_melhor_combinacao; i++) {
            printf("  - %s (Peso: %d, Valor: %d)\n", melhor_combinacao_global[i].nome, melhor_combinacao_global[i].peso, melhor_combinacao_global[i].valor);
            peso_final += melhor_combinacao_global[i].peso;
        }
        printf("Peso total na mochila: %d (Capacidade: %d)\n", peso_final, w);
    } else {
        printf("\nNenhuma combinacao de itens coube na mochila.\n");
    }

    //libera vetores alocados dinamicamente
    free(itens);
    free(combinacao_atual);
    free(melhor_combinacao_global);

    return 0;
}