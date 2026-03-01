#include <stdio.h>
#include <string.h>

int main(){
    char str[105];
    fgets(str, sizeof(str), stdin);
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] == str[j] && str[i] != '\n') {
                printf("Caracter repetido: %c na posicao %d e %d\n", str[i], (i + 1), (j + 1));
            }
        }
    }
    return 0;
}