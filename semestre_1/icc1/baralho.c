#include <stdio.h>

int main() {
    int n, i, carta, naipe;
    int baralho[4][13] = {0};
    char str[4];
    char *valores[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", str);

        if (str[0] == '1' && str[1] == '0') carta = 9;
        else if (str[0] == 'A') carta = 0;
        else if (str[0] >= '2' && str[0] <= '9') carta = str[0] - '1';
        else if (str[0] == 'J') carta = 10;
        else if (str[0] == 'Q') carta = 11;
        else if (str[0] == 'K') carta = 12;

        int idx;
        if (str[0] == '1' && str[1] == '0') {
            idx = 2;
        } else {
            idx = 1;
        }
        switch (str[idx]) {
            case 'C': naipe = 0; break;
            case 'O': naipe = 1; break;
            case 'P': naipe = 2; break;
            case 'E': naipe = 3; break;
        }

        baralho[naipe][carta]++;
    }

    for (int n = 0; n < 4; n++) {
        switch (n) {
            case 0: printf("Naipe: Copas\n"); break;
            case 1: printf("Naipe: Ouros\n"); break;
            case 2: printf("Naipe: Paus\n"); break;
            case 3: printf("Naipe: Espadas\n"); break;
        }

        for (int j = 0; j < 13; j++) {
            printf("%s: %d\n", valores[j], baralho[n][j]);
        }
    }
    return 0;
}
