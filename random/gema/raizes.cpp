#include <iostream>
using namespace std;

int main()
{
    string numeros;
    int i=1,n;
    cin>>n>>numeros;
    while (i<=n)
     {
        cout<<numeros[i]*numeros[i]<<" ";
        i++;
     }
    return 0;
}