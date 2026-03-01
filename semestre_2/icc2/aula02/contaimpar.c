#include <stdio.h>

int conta_impar(int v[], int i, int n){ //conta quantos impares tem em um array
    if (i < 0 || i >= n){
        return 0;
    }
    
    if (v[i] % 2 == 1){
        return 1 + conta_impar(v, i + 1, n);
    }
    else{
        return conta_impar(v, i + 1, n);
    }
}

int mdc(int p, int q){ //acha o mdc entre 2 numeros
    if (q == 0){
        return p;
    }
    else{
        return mdc(q, p % q);
    }
//assumindo que p > q)
}

int palindromo(char *str, int length){ //verifica se é palindromo (tipo arara)
    if (length < 1){
        return 1;
    }
    if (str[0] == str[length - 1]){
        return palindromo(str + 1, length - 2);
    }
    else{
        return 0;
    }
}

int busca_binaria(int v[], int chave , int inicio, int length){
    int meio = (inicio + length) / 2;
    if (length < inicio){
        return -1;
    }
    if (chave == v[meio]){
        return meio;
    }
    else{
        if(chave > v[meio]){
            busca_binaria(v, chave, meio, length);
        }
        else{
            busca_binaria(v, chave, inicio, length);
        }
    }
}

int main(){
    int n = mdc(60,45);
    printf("mdc entre 60 e 45:%d\n", n);

    int v[7] = {1,3,4,6,8,9,10};
    int resul = busca_binaria(v, 9, 0, 6);
    printf("Indice de 9: %d\n", resul);

    return 0;
    //fazer busca binaria sem recursão
}