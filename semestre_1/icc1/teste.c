#include <stdio.h>

int main(){
    double s,x,termo,div;
    int i,j,k;
    scanf("%lf", &x);
    s=x;
    for (i=0;i<20;i=i+1){
        termo=1;
        div=1;
        for (j=0;j<(2*i);j=j+1){
            termo=termo*x;
        }
        for (k=1;k<=(2*i+1);k=k+1) {
            div=div*k;
        }
        termo=termo/div;
        if (i % 2 != 0){
            termo=-termo;
        }
        s=s+termo;
    }
    printf("%lf",s);
    return 0;
}