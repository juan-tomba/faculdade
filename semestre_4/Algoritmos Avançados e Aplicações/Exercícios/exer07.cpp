#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> preco(n), sat(n);
        for (int i = 0; i < n; i++) {
            cin >> preco[i] >> sat[i];
        }

        // o maximo que da pra gastar eh m + 200 (se a promocao ativar)
        int cap = m + 200;

        // dp[j] = maior satisfacao gastando EXATAMENTE j
        // -1 significa que nao da pra gastar exatamente j
        vector<int> dp(cap + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = cap; j >= preco[i]; j--) {
                if (dp[j - preco[i]] != -1) {
                    dp[j] = max(dp[j], dp[j - preco[i]] + sat[i]);
                }
            }
        }

        int resposta = 0;
        for (int j = 0; j <= cap; j++) {
            if (dp[j] == -1) continue;

            // vale se cabe no orcamento original ou se passou de 2000 (ai ganha os 200 de credito)
            if (j <= m || j > 2000) {
                resposta = max(resposta, dp[j]);
            }
        }

        cout << resposta << endl;
    }

    return 0;
}