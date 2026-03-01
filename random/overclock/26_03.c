#include <stdio.h>
#include <math.h>
#define constante 10

int main(){
    float num=1.00000000009;
    printf("num= %f\n", num);
    unsigned int u= -2;
    printf("u vale %u\n", u);
    char c= 'A';
    printf ("Char; %c\n",c);
    printf ("Inteiro; %d\n",c);
    printf ("Endereço de c; %p\n", &c);
    printf ("Constante; %d\n",constante);
    return 0;
}