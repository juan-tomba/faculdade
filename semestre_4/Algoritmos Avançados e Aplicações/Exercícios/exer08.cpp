#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        // cresc[i] = maior sequencia crescente comecando em i
        // decr[i] = maior sequencia decrescente comecando em i
        vector<int> cresc(n, 1), decr(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (w[j] > w[i]) {
                    cresc[i] = max(cresc[i], cresc[j] + 1);
                }
                if (w[j] < w[i]) {
                    decr[i] = max(decr[i], decr[j] + 1);
                }
            }
        }

        int maiorCresc = 0, maiorDecr = 0;
        for (int i = 0; i < n; i++) {
            maiorCresc = max(maiorCresc, cresc[i]);
            maiorDecr = max(maiorDecr, decr[i]);
        }

        cout << maiorCresc + maiorDecr - 1 << endl;
    }

    return 0;
}