#include <stdio.h>

int main(){
    char letra;
    int maiuscula, minuscula;
    maiuscula=0;
    minuscula=0;
    int confere=0;;
    do{
        scanf(" %c", &letra);
        confere=(int)letra;
        if ((confere>=65) && (confere<=90)) maiuscula=maiuscula+1;
        if ((confere>=97) && (confere<=122)) minuscula=minuscula+1;
    }while (confere!=64);
    printf("Letras Maiusculas:%d\n", maiuscula);
    printf("Letras Minusculas:%d\n", minuscula);
    return 0;
}