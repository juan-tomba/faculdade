#include <stdio.h>
#include <string.h>

int main(){
    int n, b;
    char str[105];
    scanf("%d %d", &n, &b);
    fgets(str, sizeof(str), stdin);
    
    if (b == 0){
        for (int i = 0; i < n; i++){
            fgets(str, sizeof(str), stdin);

            int len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }

            for (int j = 0; str[j] != '\0'; j++){
                int conta = str[j];
                if (conta > 64 && conta < 91){
                    str[j] = str[j] + 32;
                }
            }
        printf("%s\n", str);    
        }
    }
    if (b == 1){
        for (int i = 0; i < n; i++){
            fgets(str, sizeof(str), stdin);

            int len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }

            for (int j = 0; str[j] != '\0'; j++){
                int conta = str[j];
                if (conta > 96 && conta < 123){
                    str[j] = str[j] - 32;
                }
            }
        printf("%s\n", str);
        }
    }

    return 0;
}