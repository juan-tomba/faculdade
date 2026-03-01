#include <stdio.h>
#include <string.h>

int busca_binaria_recursiva(int v[], int esq, int dir, int x){
    if (dir >= esq){
        int meio = (esq + dir) / 2;
        if (x == v[meio])
            return meio;
        else if (x < v[meio])
            return busca_binaria_recursiva(v, esq, meio - 1, x);
        else
            return busca_binaria_recursiva(v, meio + 1, dir, x);
    }
    return -1;
}

int busca_interpolação(int v[], int esq, int dir, int x){
    int n_it = 0;
    while(dir >= esq){
        n_it++;
        int meio = esq + (int)((dir - esq) * ((double)(x - v[esq]) / (v[dir] - v[esq])));
        if (x == v[meio])
            return meio;
        else if (x < v[meio])
            dir = meio - 1;
        else
            esq = meio + 1;
    }
    return -1;
}


int main(){
    int v[] = {1,5,8,14,16,18,20,22,25,28,30,31,32,35,38,40,42,46,48,50}; // n = 20
    int chave;
    printf("Escolha o elemento a ser buscado: ");
    scanf("%d", &chave);

    printf("\n");
    printf("%d\n", busca_interpolação(v, 0, 19, 48));

    return 0;
}