#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct estatistica_ Est;

struct estatistica_ {
    unsigned int comparacoes;
    unsigned int movimentacoes;
    double tempo;
};

void resetarEstatistica(Est* est){
    est->comparacoes = 0;
    est->movimentacoes = 0;
    est->tempo = 0.0;
}

struct timespec inicio, fim;


void swap(int* a, int* b, Est* est){
    int temp;
    temp = *a; est->movimentacoes++;
    *a = *b; est->movimentacoes++;
    *b = temp; est->movimentacoes++;
}

int* montaOrdenado(int n){
    int* vetor = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        vetor[i] = i;

    return vetor;
}

int* montaReversamenteOrdenado(int n){
    int* vetor = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        vetor[i] = n - i - 1;

    return vetor;
}

int* montaAleatorio(int n, unsigned int seed){
    int* vetor = (int*)malloc(sizeof(int) * n);
    srand(seed);
    for (int i = 0; i < n; i++)
        vetor[i] = rand() % n;
    
    return vetor;
}

void BubbleSort(int v[], int n, Est* est){
    for (int i = 0; i < n; i++){
        int trocas = 0;
        for (int j = 0; j < n - i - 1; j++){
            est->comparacoes++;
            if (v[j] > v[j+1]){
                swap(&v[j], &v[j+1], est);
                trocas++;
            }
        }
        if (!trocas) return;
    }
}

void SelectionSort(int v[], int n, Est* est){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            est->comparacoes++;
            if (v[j] < v[min]) min = j;
        }

        if (min != i){
            swap(&v[min], &v[i], est);
        }
    }
}


void InsertionSort(int v[], int n, Est* est){
    for (int i = 1; i < n; i++){
        int atual_analisado = v[i];
        int j = i - 1;
        
        // A primeira comparação é antes do loop.
        // A comparação v[j] > atual_analisado é feita dentro do while.

        while (j >= 0){
            est->comparacoes++; // Contamos a comparação v[j] > atual_analisado
            if (v[j] > atual_analisado){
                est->movimentacoes++;
                v[j+1] = v[j];
                j--;
            } else {
                break;
            }
        }
        // Uma movimentação para colocar o elemento na posição correta
        est->movimentacoes++;
        v[j+1] = atual_analisado;
    }
}

void ShellSort(int v[], int n, Est* est){
    for (int pulo = n/2; pulo > 0; pulo /= 2){
        for (int j = pulo; j < n; j ++){
            int atual_analisado = v[j];
            int k = j - pulo;
            
            // Loop de comparação e deslocamento
            while (k >= 0){
                est->comparacoes++;
                if (v[k] > atual_analisado){
                    est->movimentacoes++;
                    v[k + pulo] = v[k];
                    k -= pulo;
                } else {
                    break;
                }
            }
            
            // Uma movimentação para colocar o elemento na posição correta
            est->movimentacoes++;
            v[k + pulo] = atual_analisado;
        }
    }
}

void QuickSort(int v[], int inicio, int fim, Est* est){
    if (inicio >= fim) return;

    int meio = (fim + inicio) / 2;
    
    // Mediana de três (comparação e swap)
    est->comparacoes += 3; // Estimando 3 comparações no total (não é estritamente 3, mas simplifica a contagem)

    if (v[inicio] > v[meio]){
        swap(&v[inicio], &v[meio], est);
    } 
    if (v[meio] > v[fim]){
        swap(&v[meio], &v[fim], est);
    } 
    if (v[inicio] > v[meio]){
        swap(&v[inicio], &v[meio], est);
    }

    swap(&v[meio], &v[fim], est); 

    int pivo = v[fim];

    int i = inicio;
    for (int j = inicio; j < fim; j++){
        est->comparacoes++;
        if (v[j] < pivo){
            swap(&v[i], &v[j], est);
            i++;
        }
    }

    swap(&v[i], &v[fim], est); 

    QuickSort(v, inicio, i - 1, est);
    QuickSort(v, i + 1, fim, est);
}

void Heapify(int v[], int n, int i, Est* est){
    
    int maior = i;

    int esq = 2*i + 1;
    int dir = 2*i + 2;

    est->comparacoes++;
    if (esq < n && v[esq] > v[maior])
        maior = esq;
    
    est->comparacoes++;
    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i){
        swap(&v[i], &v[maior], est);
        Heapify(v, n, maior, est);
    }

}

void HeapSort(int v[], int n, Est* est){
    for (int i = n/2 - 1; i >= 0; i--){
        Heapify(v, n, i, est);
    }

    for (int i = n - 1; i >= 0; i--){
        swap(&v[0], &v[i], est);
        Heapify(v, i, 0, est);
    }
}

void Merge(int v[], int inicio, int meio, int fim, Est* est){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int* esq = (int*)malloc(sizeof(int) * n1);
    int* dir = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++){
        esq[i] = v[inicio + i];
    }
    est->movimentacoes += n1;

    for (int i = 0; i < n2; i++){
        dir[i] = v[meio + i + 1];
    }
    est->movimentacoes += n2;

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2){
        est->comparacoes++;

        if (esq[i] <= dir[j]){ 
            v[k++] = esq[i++];
        }
        
        else { 
            v[k++] = dir[j++];
        }
        est->movimentacoes++;
    }

    while (i < n1){
        v[k++] = esq[i++];
        est->movimentacoes++;
    }

    while (j < n2){
        v[k++] = dir[j++];
        est->movimentacoes++;
    }

    free(esq);
    free(dir);
}

void MergeSort(int v[], int inicio, int fim, Est* est){
    if (inicio < fim){ 
        int meio = inicio + (fim - inicio) / 2;
        MergeSort(v, inicio, meio, est);
        MergeSort(v, meio + 1, fim, est);
        Merge(v, inicio, meio, fim, est);
    }
}

void ContagemDosMenores(int v[], int n, Est* est){
    int* aux = (int*)calloc(n, sizeof(int));
    int* final = (int*)malloc(sizeof(int) * n);

    for(int i = 1; i < n; i++){
        for (int j = i - 1; j >= 0; j--){
            est->comparacoes++;

            if (v[i] < v[j])
                aux[j]++;
            else
                aux[i]++;
        } 
    }

    for (int i = 0; i < n; i++){
        final[aux[i]] = v[i];
        est->movimentacoes++;
    }

    for (int i = 0; i < n; i++){
        v[i] = final[i];
        est->movimentacoes++;
    }

    free(aux);
    free(final);
}

void CountingSortPorDigito(int v[], int n, int exp, Est* est){
    int* saida = (int*)malloc(n * sizeof(int));
    int cont[10] = {0};

    for (int i = 0; i < n; i++)
        cont[(v[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        cont[i] += cont[i - 1];

    for (int i = n - 1; i >= 0; i--){
        int dig = (v[i] / exp) % 10;
        saida[cont[dig] - 1] = v[i];
        cont[dig]--;
        est->movimentacoes++;
    }

    for (int i = 0; i < n; i++){
        v[i] = saida[i];
        est->movimentacoes++;
    }

    free(saida);
}

void RadixSort(int v[], int n, Est* est){
    int maior = v[0];

    for (int i = 1; i < n; i++){
        est->comparacoes++;
        if (v[i] > maior) maior = v[i];
    }

    for (int exp = 1; maior / exp > 0; exp *= 10)
        CountingSortPorDigito(v, n, exp, est);
}

FILE* criarCSV(const char* nome){
    FILE* arq = fopen(nome, "w");
    if (arq == NULL){
        perror("Erro ao criar arquivo");
        exit(1);
    }
    fprintf(arq, "algoritmo,tipo,tamanho,comparacoes,movimentacoes,tempo\n");
    return arq;
}

void salvarCSV(FILE* f, const char* algoritmo, const char* tipo, int n, Est *e){
    fprintf(f, "%s,%s,%d,%u,%u,%.10f\n",
        algoritmo, 
        tipo, 
        n, 
        e->comparacoes, 
        e->movimentacoes, 
        e->tempo
    );
}

void copiarVetor(int original[], int copia[], int n){
    for (int i = 0; i < n; i++){
        copia[i] = original[i];
    }
}

void rodarTodos(int v[], const char* tipo, int n, FILE* arq){
    int* copia = (int*)malloc(sizeof(int) * n);
    Est est; // Struct alocada na pilha
    double tempo_gasto;

    // BubbleSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    BubbleSort(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Bubble", tipo, n, &est);

    // SelectionSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    SelectionSort(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Selection", tipo, n, &est);

    // InsertionSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    InsertionSort(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Insertion", tipo, n, &est);

    // ShellSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    ShellSort(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Shell", tipo, n, &est);

    // QuickSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    QuickSort(copia, 0, n-1, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Quick", tipo, n, &est);

    // HeapSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est); 
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    HeapSort(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Heap", tipo, n, &est);

    // MergeSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    MergeSort(copia, 0, n-1, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Merge", tipo, n, &est);

    // ContagemDosMenores
    copiarVetor(v, copia, n);
    resetarEstatistica(&est); 
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    ContagemDosMenores(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "ContagemMenores", tipo, n, &est);
    
    // RadixSort
    copiarVetor(v, copia, n);
    resetarEstatistica(&est); 
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    RadixSort(copia, n, &est);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    est.tempo = tempo_gasto;
    salvarCSV(arq, "Radix", tipo, n, &est);

    free(copia);
}

void rodarTodosAleatorio(int* v[], int n, FILE* arq){
    const char* nomes[9] = {"Bubble","Selection","Insertion","Shell","Quick","Heap","Merge","ContagemDosMenores","Radix"};
    Est somaTotal[9];
    
    Est est; // Estrutura local para coletar dados temporários

    for (int i = 0; i < 9; i++)
        resetarEstatistica(&somaTotal[i]);

    for (int i = 0; i < 5; i++){ // Loop para os 5 vetores aleatórios
        int* original = v[i];
        int* copia = (int*)malloc(sizeof(int) * n);
        double tempo_gasto;

        // --- BubbleSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        BubbleSort(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[0].comparacoes += est.comparacoes;
        somaTotal[0].movimentacoes += est.movimentacoes;
        somaTotal[0].tempo += est.tempo;
        
        // --- SelectionSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        SelectionSort(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[1].comparacoes += est.comparacoes;
        somaTotal[1].movimentacoes += est.movimentacoes;
        somaTotal[1].tempo += est.tempo;
        
        // --- InsertionSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        InsertionSort(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[2].comparacoes += est.comparacoes;
        somaTotal[2].movimentacoes += est.movimentacoes;
        somaTotal[2].tempo += est.tempo;
        
        // --- ShellSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        ShellSort(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[3].comparacoes += est.comparacoes;
        somaTotal[3].movimentacoes += est.movimentacoes;
        somaTotal[3].tempo += est.tempo;
        
        // --- QuickSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        QuickSort(copia, 0, n-1, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[4].comparacoes += est.comparacoes;
        somaTotal[4].movimentacoes += est.movimentacoes;
        somaTotal[4].tempo += est.tempo;
        
        // --- HeapSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        HeapSort(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[5].comparacoes += est.comparacoes;
        somaTotal[5].movimentacoes += est.movimentacoes;
        somaTotal[5].tempo += est.tempo;
        
        // --- MergeSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        MergeSort(copia, 0, n-1, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[6].comparacoes += est.comparacoes;
        somaTotal[6].movimentacoes += est.movimentacoes;
        somaTotal[6].tempo += est.tempo;
        
        // --- ContagemDosMenores ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        ContagemDosMenores(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[7].comparacoes += est.comparacoes;
        somaTotal[7].movimentacoes += est.movimentacoes;
        somaTotal[7].tempo += est.tempo;
        
        // --- RadixSort ---
        copiarVetor(original, copia, n);
        resetarEstatistica(&est);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        RadixSort(copia, n, &est);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
        est.tempo = tempo_gasto;
        somaTotal[8].comparacoes += est.comparacoes;
        somaTotal[8].movimentacoes += est.movimentacoes;
        somaTotal[8].tempo += est.tempo;
        
        free(copia);
    }

    for (int i = 0; i < 9; i++){
        somaTotal[i].comparacoes /= 5;
        somaTotal[i].movimentacoes /= 5;
        somaTotal[i].tempo /= 5;
        salvarCSV(arq, nomes[i], "aleatorio_media", n, &somaTotal[i]);
    }
}


int main(){
    int tamanhos[4] = {100, 1000, 10000, 100000};

    FILE* arq = criarCSV("resultados.csv");
    // Seed base dinâmica para garantir que cada execução do programa gere um novo conjunto de vetores
    unsigned int baseSeed = (unsigned int)time(NULL); 

    for (int i = 0; i < 4; i++){ // Loop para os tamanhos (Controlado por 'i')

        if (i == 3)
            printf("Esse vai dermorar um pouco...\n");

        int* vetorOrdenado = montaOrdenado(tamanhos[i]);
        rodarTodos(vetorOrdenado, "Ordenado", tamanhos[i], arq);
        free(vetorOrdenado);
    
        int* vetorReversamenteOrdenado = montaReversamenteOrdenado(tamanhos[i]);
        rodarTodos(vetorReversamenteOrdenado, "Reverso", tamanhos[i], arq);
        free(vetorReversamenteOrdenado);


        int** aleatorios = (int**)malloc(sizeof(int*) * 5);
        // Geração dos 5 vetores aleatórios (Controlado por 'j')
        for (int j = 0; j < 5; j++){
            // Garante que a seed seja diferente para cada um dos 5 vetores e para cada tamanho 'i'
            unsigned int seed = baseSeed + (i * 10) + j; 
            aleatorios[j] = montaAleatorio(tamanhos[i], seed);
        }

        rodarTodosAleatorio(aleatorios, tamanhos[i], arq);
        
        // Liberação de memória (Controlado por 'k')
        for (int k = 0; k < 5; k++){
            free(aleatorios[k]);
        }
        free(aleatorios);

            
        printf("Rodando vetores de tamanho %d\n", tamanhos[i]);
        fflush(arq);

    }
    
    fclose(arq);
    return 0;
}