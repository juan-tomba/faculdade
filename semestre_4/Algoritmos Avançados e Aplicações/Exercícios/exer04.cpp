#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // cria e le a matriz n x n
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    // inicializa valor negativo 
    int max_total = -9999999;

    // trava a coluna da esquerda
    for (int l = 0; l < n; l++) {
        // vetor pra ir acumulando a soma de cada linha
        vector<int> temp(n, 0);
        
        // anda com a coluna da direita
        for (int r = l; r < n; r++) {
            // soma os elementos da nova coluna no vetor auxiliar
            for (int i = 0; i < n; i++) {
                temp[i] += mat[i][r];
            }

            // kadane no vetor temp
            int max_atual = -9999999;
            int soma = 0;
            
            for (int i = 0; i < n; i++) {
                soma += temp[i];
                
                // se achou uma soma maior, atualiza
                if (soma > max_atual) {
                    max_atual = soma;
                }
                
                // se a soma ficou negativa, zera
                if (soma < 0) {
                    soma = 0;
                }
            }

            if (max_atual > max_total) {
                max_total = max_atual;
            }
        }
    }

    cout << max_total << "\n";
    return 0;
}