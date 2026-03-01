#include <stdio.h>

int main(){
    int n,w,x,y,z,soma;
    soma=0;
    scanf("%d",&n);
    w=(n%10);
    x=(2*((n%100)/10));
    y=(4*((n%1000)/100));
    z=(8*(n/1000));
    soma=w+x+y+z;
    printf("%d", soma);
    return 0;
}