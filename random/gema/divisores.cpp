#include <iostream>

int main(){
    int i=1,n;
    std::cin>>n;
    while (i<=n) {
        if (n%i==0) std::cout<<i<<" ";
        i++;
    }
    return 0;
}