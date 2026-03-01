#include <stdio.h>

void shell_sort(int v[], int n) {
    int i, j, h, aux;
    int incr[3] = {5, 3, 1};

    for (h = 0; h < 3; h++) {
        for (i = incr[h]; i < n; i++) {
            aux = v[i];
            for (j = i - incr[h]; j >= 0 && aux < v[j]; j -= incr[h]) {
                v[j + incr[h]] = v[j];
            }
            v[j + incr[h]] = aux;
        }
    }
}


int main(){
    int v[] = {6,7,3,4,2,9,7,1,5,-3};

    shell_sort(v, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}