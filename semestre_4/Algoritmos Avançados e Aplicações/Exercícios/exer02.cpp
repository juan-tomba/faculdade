#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n, p, q;
        vector<int> ovos;
        cin >> n >> p >> q;

        for (int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            ovos.push_back(aux);
        }
        sort(ovos.begin(), ovos.end(), greater<int>());

        int count = 0;
        int gramas = 0;
        while ((count < p) && (gramas + ovos.back() <= q) && (!ovos.empty())){
            gramas += ovos.back();
            ovos.pop_back();
            count++;
        }
        cout << "Caso " << (i + 1) << ": " << count << endl;
    }

    return 0;
}