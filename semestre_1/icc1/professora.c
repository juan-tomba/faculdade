#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* texto;
} atividade;

typedef struct {
    int segundos;
    int minutos;
    int horas;
} horario;

typedef struct{
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    data d;
    horario h;
    atividade a;
} geral;

int main(){
    int n;
    scanf("%d", &n);
    geral *estrutura = malloc(n * sizeof(geral));
    for (int i = 0; i < n; i++){
        estrutura[i].a.texto = malloc(100 * sizeof(char));
        scanf("%d", &estrutura[i].d.dia);
        scanf("%d", &estrutura[i].d.mes);
        scanf("%d", &estrutura[i].d.ano);
        scanf("%d", &estrutura[i].h.horas);
        scanf("%d", &estrutura[i].h.minutos);
        scanf("%d\n", &estrutura[i].h.segundos);
        fgets(estrutura[i].a.texto, 100, stdin);

        int len = strlen(estrutura[i].a.texto);
        if (len > 0 && estrutura[i].a.texto[len - 1] == '\n') {
            estrutura[i].a.texto[len - 1] = '\0';
        }
    }

    for(int j = 0; j < n; j++){
        printf("%02d/%02d/%04d - %02d:%02d:%02d\n", estrutura[j].d.dia, estrutura[j].d.mes, estrutura[j].d.ano, estrutura[j].h.horas, estrutura[j].h.minutos, estrutura[j].h.segundos);
        printf("%s\n", estrutura[j].a.texto);
    }
    
    for (int i = 0; i < n; i++) {
        free(estrutura[i].a.texto);
    }
    free(estrutura);
    return 0;
}