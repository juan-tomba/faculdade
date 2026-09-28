#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int casos;
    cin >> casos;

    while(casos) {
        int p, c;
        cin >> p >> c;

        // vetor para armazenar os precos ideais dos aventureiros
        vector<int> av(p);
        for (int j = 0; j < p; j++) {
            cin >> av[j];
        }

        // vetor para armazenar os precos ideais dos clientes
        vector<int> cl(c);
        for (int j = 0; j < c; j++) {
            cin >> cl[j];
        }

        // vetor que reune todos os precos que serao testados
        vector<int> cand;
        cand.push_back(0); // 0 deve ser considerado
        for (int j = 0; j < p; j++) cand.push_back(av[j]);
        for (int j = 0; j < c; j++) cand.push_back(cl[j]);

        // ordena para a busca binaria
        sort(av.begin(), av.end());
        sort(cl.begin(), cl.end());
        sort(cand.begin(), cand.end());

        int min_irritados = 2000000000;
        int melhor_preco = 0;

        for (int j = 0; j < cand.size(); j++) {
            int preco_atual = cand[j];
            
            // aventureiro irritado: preco atual < preco ideal
            // upper_bound retorna o primeiro elemento maior que preco_atual (it)
            auto it_av = upper_bound(av.begin(), av.end(), preco_atual);
            int irritados_av = av.end() - it_av;

            // cliente irritado: preco atual > preco ideal
            // lower_bound retorna  o primeiro elemento maior ou igual a preco_atual
            auto it_cl = lower_bound(cl.begin(), cl.end(), preco_atual);
            int irritados_cl = it_cl - cl.begin();

            int total_irritados = irritados_av + irritados_cl;

            // atualiza o resultado se encontrar um preco que gere menos pessoas irritadas
            if (total_irritados < min_irritados) {
                min_irritados = total_irritados;
                melhor_preco = preco_atual;
            }
        }

        cout << melhor_preco << " " << min_irritados << "\n";
        casos--;
    }

    return 0;
}