#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = NULL, *t = NULL;
    int max = 10001;
    s = (char *) malloc(max * sizeof(char));
    t = (char *) malloc(max * sizeof(char));

    scanf("%s", s);
    scanf("%s", t);

    int tam_t = strlen(t);
    int tam_codigo = 0;
    int achou = 0;
    char *prefixo = (char *) malloc((tam_t + 1) * sizeof(char));

    for (int i = tam_t; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            prefixo[j] = t[j];
        }
        prefixo[i] = '\0'; 

        if (strstr(s, prefixo) != NULL) {
            tam_codigo = i;
            achou = 1;
            break;
        }
    }

    if (achou) {
        printf("%d %s\n", tam_codigo, prefixo);
    } else {
        printf("0\n");
    }

    free(s);
    free(t);
    free(prefixo);

    return 0;
}
