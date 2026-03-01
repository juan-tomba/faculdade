#include <stdio.h>

int main(){
    int x,log;
    scanf(" %d",&x);
    int ex=x;
    log=0;
    while(ex>1){
        ex=ex/2;
        log=log+1;
    }
    printf("O log de %d a base 2 eh %d", x,log);
    return 0;
}