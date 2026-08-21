#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<bool> lampadas = {false, true, false, true, false};

    int counter = 0;
    for (auto l : lampadas){
        if (!(counter % 2 == 0 ? l : !l)){
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}