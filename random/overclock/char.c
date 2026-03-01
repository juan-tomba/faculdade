#include <stdio.h>

int main(){
    char primeira_letra,segunda_letra;
    scanf(" %c", &primeira_letra);
    scanf(" %c", &segunda_letra);
    int x=(int)primeira_letra;
    char c=(char)(x+32);
    int z=(int)segunda_letra;
    char m=(char)(z-32);
    printf(" %c\n", c);
    printf(" %c\n", m);

    return 0;
}