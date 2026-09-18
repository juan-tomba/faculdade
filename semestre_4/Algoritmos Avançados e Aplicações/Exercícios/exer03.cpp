#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, caso = 1;
    cin >> n; // numero de casos de teste
    
    while (n--) {
        int t, k;
        cin >> t >> k; 
        
        int tempos[35];
        int soma = 0, maior = 0;
        
        for (int i = 0; i < t; i++) {
            cin >> tempos[i];
            soma += tempos[i];
            maior = max(maior, tempos[i]);
        }
        
        // o menor tempo possivel eh o maior show sozinho, o maior eh tudo em um dia so
        int ini = maior, fim = soma, resp = soma;
        
        while (ini <= fim) {
            int meio = (ini + fim) / 2;
            
            // simulando se cabe nos k dias com limite maximo de 'meio'
            int dias = 1, soma_dia = 0;
            for (int i = 0; i < t; i++) {
                if (soma_dia + tempos[i] > meio) {
                    dias++;
                    soma_dia = tempos[i]; // proximo dia
                } else {
                    soma_dia += tempos[i];
                }
            }
            
            if (dias <= k) {
                resp = meio;    // deu certo, salva e tenta diminuir o tempo
                fim = meio - 1; 
            } else {
                ini = meio + 1; // faltou dia
            }
        }
        
        cout << "Caso " << caso++ << ": " << resp << "\n";
    }
    
    return 0;
}