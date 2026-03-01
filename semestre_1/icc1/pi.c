#include <stdio.h>
#include <math.h>

int main(){
    float s, baixo, num, pi;
    s = 1;
    int div = 3;
    for (int i = 1 ; i < 1000 ; i++){
        baixo = (float)(div) * (div) * (div);
        num = (float)1 / baixo;
        if ( (i % 2) != 0 ){
            s = s - num;
        }
        else s = s + num;
        div = div + 2;
    }
    pi =  cbrt(32 * s);
    printf("%f", pi);
    return 0;
}