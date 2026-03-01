#include <stdio.h>

int main(){
    float a,b, base, altura, tri;
    scanf("%f %f", &a, &b);
    if (a<0) a=-a;
    if (b<0) b=-b;
    base= (b/a);
    altura= b;
    tri=(base*altura)*0.5;
    printf("%.2f", tri);
    return 0;
}