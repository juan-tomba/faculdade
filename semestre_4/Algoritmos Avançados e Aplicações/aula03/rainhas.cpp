#include <iostream>
#include <cstring>

using namespace std;

pair<int, int> primeira_rainha = pair<int, int>(1, 1);
int rainhas[8];
bool colunas_usadas[8];

bool checa_diagonal(int i, int j) {
    for (int linha = 0; linha < 8; linha++) {
        if (rainhas[linha] != -1) {
            int coluna = rainhas[linha];
            if (abs(linha - i) == abs(coluna - j)) {
                return false;
            }
        }
    }

    return true;
}

bool solve() {

    // percorre cada uma das linhas
    for (int i = 0; i < 8; i++) {
        // se uma rainha não estiver colocada em uma coluna
        if (rainhas[i] == -1) {
            // percorre cada uma das colunas
            for (int j = 0; j < 8; j++) {
                // se a coluna estiver usada
                if (colunas_usadas[j]) {
                    continue;
                }

                // checa diagonal
                if (!checa_diagonal(i, j)) {
                    continue;
                }

                // coloca rainha e tenta seguir
                rainhas[i] = j;
                colunas_usadas[j] = true;
                if (solve()) {
                    return true;
                } else {
                    rainhas[i] = -1;
                    colunas_usadas[j] = false;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (rainhas[i] == -1) {
            return false;
        }
    }

    return true;
}


int main() {
    // fill(rainhas.begin(), rainhas.end(), -1);
    memset(rainhas, -1, sizeof(rainhas));
    memset(colunas_usadas, false, sizeof(colunas_usadas));
	// fill(colunas_usadas.begin(), colunas_usadas.end(), false);
    rainhas[primeira_rainha.first] = primeira_rainha.second;
    colunas_usadas[primeira_rainha.second] = true;

    solve();

    for (auto x : rainhas) {
       cout << x; 
    }
    cout << endl;
    
	return 0;
}