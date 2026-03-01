#include <stdio.h>

int main(){
    int a,b,c,troca;
    scanf("%d %d %d", &a, &b, &c);
    if (a>b){
        troca=a;
        a=b;
        b=troca;
    }
    if (a>c){
        troca=a;
        a=c;
        c=troca;
    }
    if (b>c){
        troca=b;
        b=c;
        c=troca;
    }
    printf("%d %d %d", a,b,c);
    return 0;
}