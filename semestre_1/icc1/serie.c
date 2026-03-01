#include <stdio.h>

int main(){
    int cima, baixo;
    float s;
    s=0;
    cima=1;
    baixo=1;
    while (cima<100){
        float s2=(float)cima / baixo;
        s=s+s2;
        cima=cima+2;
        baixo=baixo+1;
    }
    printf("%f",s);
    return 0;
}