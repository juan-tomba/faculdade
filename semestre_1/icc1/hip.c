#include <stdio.h>
#include <math.h>

int main(){
    int cat1,cat2,hip, somacat;
    scanf("%d %d", &cat1,&cat2);
    somacat = cat1*cat1 + cat2*cat2;
    hip = sqrt(somacat);
    printf("%d", hip);
    return 0;
}