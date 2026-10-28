#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<string> nomes(n);
        map<string, int> grau;                 // quantas bebidas devem vir antes
        map<string, vector<string>> adj;       // A -> bebidas que vêm depois de A

        for (auto &nome : nomes) {
            cin >> nome;
            grau[nome] = 0;
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            grau[b]++;
        }

        // Min-heap com as bebidas liberadas
        priority_queue<string, vector<string>, greater<string>> liberadas;
        for (const auto &nome : nomes)
            if (grau[nome] == 0) liberadas.push(nome);

        vector<string> ordem;
        while (!liberadas.empty()) {
            string atual = liberadas.top();    // primeira em ordem alfabética
            liberadas.pop();
            ordem.push_back(atual);

            // toma a bebida atual: libera as que dependiam dela
            for (const auto &prox : adj[atual]) {
                grau[prox]--;
                if (grau[prox] == 0) liberadas.push(prox);
            }
        }

        for (size_t i = 0; i < ordem.size(); i++) {
            if (i > 0) cout << ' ';
            cout << ordem[i];
        }
        cout << ".\n";
    }
    return 0;
}