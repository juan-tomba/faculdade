#include <iostream>

using namespace std;

// queremos montar um troco de valor n
// usando a lista de moedas disponíveis
// basta dizer se é possível ou não
int N = 10;
int n_moedas = 4;
int moedas[] = {2, 3, 1};

// como não temos slicing como em python usamos
// um índice para representar em qual moeda estamos
bool solve(int soma, int moeda_atual) {

    // condições de parada
    // terminamos, sobrou 0 para preencher
    if (soma == 0) {
    	return true;
    }

    // acabaram as moedas
    if (moeda_atual == n_moedas) {
    	return false;
    }

    // consumimos mais do que precisava
    if (soma < 0) {
        return false;
    }

    bool res1 = solve(soma - moedas[moeda_atual], moeda_atual+1);
    bool res2 = solve(soma, moeda_atual+1);

    return res1 || res2;
}


int main() {
	cout << solve(N, 0) << endl;

	return 0;
}