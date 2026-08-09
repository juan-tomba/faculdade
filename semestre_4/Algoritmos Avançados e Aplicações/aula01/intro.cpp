#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

template <typename T1, typename T2> 
T1 add(T1 a, T2 b) {
	return a + b;
}

template <typename T, int size>
class MyAmazingList {
public:
	T l[size];

	int get_size() {
		return size;
	}
};

template <typename T>
struct SmallerThan {
	bool operator()(T a, T b) {
		return a < b;
	}
};

template <typename T>
struct SmallerThanX {
	int x;

	SmallerThanX(int x_): x(x_) {} 

	bool operator()(T a) {
		return a < x;
	}
};

int main() {

	// templates
	int a = 10;
	float b = 1.1;

	// notem como o valor de retorno muda conforme 
	// mudamos quem é T1 e T2
	cout << add(a, b) << endl;
	cout << add(b, a) << endl;

	// templates também são usados em classes
	MyAmazingList<int, 10> lista;
	lista.l[9] = 10;
	cout << lista.l[9] << endl;

	// e são muitos usados na std
	vector<float> minha_lista = {10, 2.5, 2, 3, 4.4, 5.5};
	minha_lista.push_back(1.1);
	cout << minha_lista[2] << endl;

	// functors são funções com estado
	// e também uma forma de passar funções como parâmetro

	// aqui estamos passando o functor que compara valores
	sort(minha_lista.begin(), minha_lista.end(), SmallerThan<float>());
	cout << minha_lista[0] << endl;

	// aqui estamos criando um functor que tem um estado (threshold)
	cout << count_if(minha_lista.begin(), minha_lista.end(), SmallerThanX<float>(4)) << endl;

	// iteradores

	// o mais tradicional
	for (auto it = minha_lista.begin(); it != minha_lista.end(); it++) {
		cout << *it << " ";
	}

	// a nova forma (C++11)
	for (auto x : minha_lista) {
		cout << x << " ";
	}
	cout << endl;

	// mapas
	map<string,int> nosso_mapa;
	nosso_mapa["chave"] = 10;
	nosso_mapa["aula0"] = 20;

	// iteração sobre mapas também, temos algumas opções

	// mais usual
	for (auto& p : nosso_mapa) {
		cout << p.first << ", " << p.second << " | ";
	}
	cout << endl;

	// novo modo do C++17 
	for (auto& [key, value] : nosso_mapa) {
		cout << key << ", " << value << " | ";
	}
	cout << endl;

}