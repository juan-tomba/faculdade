#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void backtracking(vector<string> &cores, vector<string> &atual, vector<bool> &usado, vector<pair<string,string>> &errados,
                  int &quantidade, vector<string> &melhor) {

    if (atual.size() == cores.size()) {

        quantidade++;

        if (melhor.empty()) {
            melhor = atual;
        }

        return;
    }

    for (int i = 0; i < cores.size(); i++) {

        if (usado[i])
            continue;

        bool pode = true;

        // verifica apenas com a ultima cor
        if (!atual.empty()) {

            string ultima = atual.back();

            for (auto par : errados) {

                if ((par.first == cores[i] && par.second == ultima) || (par.first == ultima && par.second == cores[i])) {
                    pode = false;
                }
            }
        }

        if (!pode)
            continue;

        // escolhe
        usado[i] = true;
        atual.push_back(cores[i]);

        backtracking(cores, atual, usado, errados,
                     quantidade, melhor);

        // volta atrás
        atual.pop_back();
        usado[i] = false;
    }
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int n;
        cin >> n;

        vector<string> cores; // ordem decrescente de preferência

        for (int j = n; j > 0; j--) {

            string cor;
            cin >> cor;

            cores.push_back(cor);
        }

        vector<pair<string, string>> errados; // vetor de pairs, com os pares sendo horriveis juntos

        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            string cor;
            string cor2;

            cin >> cor >> cor2;

            errados.push_back({cor, cor2});
        }

        vector<string> atual;
        vector<bool> usado(n, false);

        vector<string> melhor;

        int quantidade = 0;

        backtracking(cores, atual, usado, errados, quantidade, melhor);

        cout << quantidade << endl;

        for (string cor : melhor) {
            cout << cor << " ";
        }

        cout << endl;
    }

    return 0;
}