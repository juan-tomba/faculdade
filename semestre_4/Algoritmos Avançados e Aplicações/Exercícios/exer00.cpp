#include <iostream>

using namespace std;

int main(){
    int casos;
    cin >> casos;
    int resultado[casos]; 

    for (int i = 0; i < casos; i++){ // numero de casos
        int num;
        cin >> num;
        int vetor[num];// vetor que armazena qual direção é a instrução (se for repete, coloca tbm no valor)

        int pos = 0; // posicao atual do teste
        
        for (int j = 0; j < num; j++){
            string entrada;
            cin >> entrada;

            if (entrada == "ESQUERDA"){
                pos--;
                vetor[j] = -1;
            }

            else if (entrada == "DIREITA"){
                pos++;
                vetor[j] = 1;
            }

            else{
                int iesima;
                cin >> iesima; // numero da repetição

                pos += vetor[iesima];  // soma, pq o valor é positivo ou negativo
                vetor[j] = vetor[iesima]; // atribui a iesima posição ao vetor na posição repetida
            }
        }
        resultado[i] = pos; // vetor de resultados
    }

    for (int i = 0; i < casos; i++){
        cout << resultado[i] << endl;
    }

    return 0;
}