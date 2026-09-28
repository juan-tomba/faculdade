#include <iostream>

using namespace std;

int main() {
    int casos;
    cin >> casos;

    
    while (casos) {
        int l, n;
        cin >> l >> n;

        int min_total = 0;
        int max_total = 0;

        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;

            // distancia pra borda da esquerda e da direita
            int dist_esq = pos;
            int dist_dir = l - pos;

            // tempo minimo = ir pro lado com menos dist
            int tempo_min;
            if (dist_esq < dist_dir) {
                tempo_min = dist_esq;
            } else {
                tempo_min = dist_dir;
            }
            
            // tempo maximo= ir pro lado com mais dist
            int tempo_max;
            if (dist_esq > dist_dir) {
                tempo_max = dist_esq;
            } else {
                tempo_max = dist_dir;
            }

            // o tempo total eh sempre o do prisioneiro que demora mais pra cair
            if (tempo_min > min_total) {
                min_total = tempo_min;
            }
            if (tempo_max > max_total) {
                max_total = tempo_max;
            }
        }

        // printa separado por espaco
        cout << min_total << " " << max_total << "\n";
    
        casos--;
    }

    return 0;
}