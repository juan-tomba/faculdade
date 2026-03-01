#include <stdio.h>

int main(){
    int i = 10;
    int *p = &i;
    printf("%d bytes\n", sizeof(p));
    printf("%d bytes\n", sizeof(i));
    return 0;
}