#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> casos(T);
    int maior = 0;

    // le os casos e guarda o maior valor
    for (int i = 0; i < T; i++) {
        cin >> casos[i];

        if (casos[i] > maior) {
            maior = casos[i];
        }
    }

    // marca os numeros que sao primos
    vector<bool> primo(maior + 1, true);
    primo[0] = false;
    primo[1] = false;

    // usa o crivo para encontrar os primos
    for (int i = 2; i * i <= maior; i++) {
        if (primo[i]) {
            for (int j = i * i; j <= maior; j += i) {
                primo[j] = false;
            }
        }
    }

    // guarda os primos em ordem crescente
    vector<int> primos;

    for (int i = 2; i <= maior; i++) {
        if (primo[i]) {
            primos.push_back(i);
        }
    }

    // calcula a senha de cada caso
    for (int c = 0; c < T; c++) {
        int n = casos[c];
        string senha = "";

        // se o proprio numero for primo, ele ja e a melhor resposta
        if (primo[n]) {
            cout << n << endl;
            continue;
        }

        bool encontrou = false;

        // procura uma soma com dois primos
        for (int i = 0; i < (int)primos.size(); i++) {
            int p = primos[i];
            int resto = n - p;

            if (resto <= p) {
                break;
            }

            if (primo[resto]) {
                senha = to_string(p) + to_string(resto);
                encontrou = true;
                break;
            }
        }

        // se nao encontrou dois primos, procura uma soma com tres
        if (!encontrou) {
            for (int i = 0; i < (int)primos.size() && !encontrou; i++) {
                int p = primos[i];

                for (int j = i + 1; j < (int)primos.size(); j++) {
                    int q = primos[j];
                    int resto = n - p - q;

                    // os primos precisam estar em ordem crescente
                    if (resto <= q) {
                        break;
                    }

                    if (primo[resto]) {
                        senha = to_string(p) + to_string(q) + to_string(resto);
                        encontrou = true;
                        break;
                    }
                }
            }
        }

        cout << senha << endl;
    }

    return 0;
}