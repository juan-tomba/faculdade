#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximo de 1000 registros
#define MAX 1000

// estrutura do registro
typedef struct {
    int id;
    char login[16];
    char password[31];
    char gender;
    double salary;
    int ativo; // 1-ativo, 0-inativo
} Registro;
Registro* banco[MAX] = {NULL};

// função para remover aspas
void remove_aspas(char* str) {
    int len = strlen(str);
    if (len >= 2 && str[0] == '"' && str[len - 1] == '"') {
        for (int i = 1; i < len - 1; i++) {
            str[i - 1] = str[i];
        }
        str[len - 2] = '\0';
    }
}

// lê o arquivo e armazena os registros no banco
int carregar_json(const char* nome_arquivo) {
    FILE* f = fopen(nome_arquivo, "r");
    if (!f) {
        printf("0 registro(s) lido(s).\n");
        return 0;
    }

    char linha[256];
    int count = 0;

    fgets(linha, sizeof(linha), f);

    while (count < MAX) {
        // lê as linhas, desconsiderando caracteres invalidos (como "[")
        if (fgets(linha, sizeof(linha), f) == NULL || !strstr(linha, "{")) {
            break; 
        }

        banco[count] = malloc(sizeof(Registro));
        if (banco[count] == NULL) { exit(1); }
        banco[count]->ativo = 1;
        // lê as linhas no formato certo
        for (int i = 0; i < 5; i++) {
            if (fgets(linha, sizeof(linha), f) == NULL) break;
            if (strstr(linha, "\"id\"")) {
                sscanf(strstr(linha, ":") + 1, "%d", &banco[count]->id);
            } else if (strstr(linha, "\"login\"")) {
                sscanf(strstr(linha, ":") + 1, " \"%[^\"]\"", banco[count]->login);
            } else if (strstr(linha, "\"password\"")) {
                sscanf(strstr(linha, ":") + 1, " \"%[^\"]\"", banco[count]->password);
            } else if (strstr(linha, "\"gender\"")) {
                sscanf(strstr(linha, ":") + 1, " \"%c\"", &banco[count]->gender);
            } else if (strstr(linha, "\"salary\"")) {
                sscanf(strstr(linha, ":") + 1, "%lf", &banco[count]->salary);
            }
        }
        
        fgets(linha, sizeof(linha), f);
        count++;
    }

    fclose(f);
    printf("%d registro(s) lido(s).\n", count);
    return count;
}

// imprime os registros
void imprimir(Registro* r) {
    printf("{\n");
    printf("    \"id\": %d,\n", r->id);
    printf("    \"login\": \"%s\",\n", r->login);
    printf("    \"password\": \"%s\",\n", r->password);
    printf("    \"gender\": \"%c\",\n", r->gender);
    printf("    \"salary\": %.2lf\n", r->salary);
    printf("}\n");
}

// função para busca (comando 2)
void buscar(const char* campo, const char* valor) {
    int encontrados = 0;
    for (int i = 0; i < MAX; i++) {
        if (banco[i] != NULL && banco[i]->ativo) {
            // verifica se é o campo que está sendo buscado
            int match = 0;
            if (strcmp(campo, "id") == 0 && atoi(valor) == banco[i]->id) match = 1;
            else if (strcmp(campo, "login") == 0 && strcmp(valor, banco[i]->login) == 0) match = 1;
            else if (strcmp(campo, "password") == 0 && strcmp(valor, banco[i]->password) == 0) match = 1;
            else if (strcmp(campo, "gender") == 0 && valor[0] == banco[i]->gender) match = 1;
            else if (strcmp(campo, "salary") == 0 && atof(valor) == banco[i]->salary) match = 1;
            // imprime se for o registro buscado, e conta
            if(match) {
                imprimir(banco[i]);
                encontrados++;
            }
        }
    }
    if (encontrados == 0) {
        printf("Nada encontrado.\n");
    }
}

// função para remover (comando 3)
void remover(const char* campo, const char* valor) {
    // conta quantos registros foram removidos
    int removidos = 0;
    if (strcmp(campo, "id") != 0 && strcmp(campo, "login") != 0 && 
        strcmp(campo, "password") != 0 && strcmp(campo, "gender") != 0 && 
        strcmp(campo, "salary") != 0) {
        printf("Remoção inválida.\n");
        return;
    }   
    // percorre o banco e remove os registros
    for (int i = 0; i < MAX; i++) {
        if (banco[i] != NULL && banco[i]->ativo) {
            int match = 0;
            if (strcmp(campo, "id") == 0 && atoi(valor) == banco[i]->id) match = 1;
            else if (strcmp(campo, "login") == 0 && strcmp(valor, banco[i]->login) == 0) match = 1;
            else if (strcmp(campo, "password") == 0 && strcmp(valor, banco[i]->password) == 0) match = 1;
            else if (strcmp(campo, "gender") == 0 && valor[0] == banco[i]->gender) match = 1;
            else if (strcmp(campo, "salary") == 0 && atof(valor) == banco[i]->salary) match = 1;
            // marca o registro como inativo e conta
            if(match) {
                banco[i]->ativo = 0;
                removidos++;
            }
        }
    }
    if (removidos > 0) {
        printf("%d registro(s) removido(s).\n", removidos);
    } else {
        printf("Remoção inválida.\n");
    }
}

// função para inserir, utilizando first-fit (comando 1)
void inserir(int id, char* login, char* password, char gender, double salary) {
    int pos_insercao = -1;
    for (int i = 0; i < MAX; i++) {
        // procura a primeira posição livre
        if (banco[i] == NULL || !banco[i]->ativo) {
            pos_insercao = i;
            break;
        }
    }
    // aloca memória se o registro for NULL
    if (pos_insercao != -1) {
        if (banco[pos_insercao] == NULL) {
            banco[pos_insercao] = malloc(sizeof(Registro));
            if(banco[pos_insercao] == NULL) exit(1);
        }
        banco[pos_insercao]->id = id;
        strcpy(banco[pos_insercao]->login, login);
        strcpy(banco[pos_insercao]->password, password);
        banco[pos_insercao]->gender = gender;
        banco[pos_insercao]->salary = salary;
        banco[pos_insercao]->ativo = 1;
        printf("Registro inserido.\n");
    } else {
        printf("Sem espaço para inserção.\n");
    }
}

int main() {
    char arquivo[100];
    // lê o nome do arquivo
    scanf("%s", arquivo);
    getchar(); 
    carregar_json(arquivo);
    char linha[256];
    // lê as linhas da entrada
    while (fgets(linha, sizeof(linha), stdin)) {
        if (strlen(linha) < 2) continue;

        int comando = 0;
        sscanf(linha, "%d", &comando);
        // verifica qual comando deve ser executado e executa
        if (comando == 1) {
            int id;
            char login[64], password[64], gender_str[4];
            double salary;
            if (sscanf(linha, "1 %d \"%[^\"]\" \"%[^\"]\" \"%1s\" %lf", &id, login, password, gender_str, &salary) == 5){
                 inserir(id, login, password, gender_str[0], salary);
            }
        } else if (comando == 2) {
            char campo[64], valor[64];
            if (sscanf(linha, "2 \"%[^\"]\" %[^\n]", campo, valor) == 2){
                remove_aspas(valor);
                buscar(campo, valor);
            } else {
                 printf("Nada encontrado.\n");
            }
        } else if (comando == 3) {
            char campo[64], valor[64];
            if (sscanf(linha, "3 \"%[^\"]\" %[^\n]", campo, valor) == 2){
                remove_aspas(valor);
                remover(campo, valor);
            } else {
                printf("Remoção inválida.\n");
            }
        }
    }
    // libera a memória alocada
    for (int i = 0; i < MAX; i++) {
        if (banco[i] != NULL) {
            free(banco[i]);
        }
    }

    return 0;
}