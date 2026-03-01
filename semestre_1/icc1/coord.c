#include <stdio.h>

int main(){
    float x,y;
    scanf("%f %f", &x, &y);
    if((x>0) & (y>0)){
        if ((y<(3*x)) & (3*y>x)) printf("INTERNO");
        else printf("EXTERNO");
    }
    else if ((x<0) & (y<0)){
        if ((y>(3*x)) & (3*y<x)) printf("INTERNO");
        else printf("EXTERNO");
    }
    else printf("EXTERNO");
    return 0;
}