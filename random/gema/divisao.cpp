#include <iostream>

int main(){
    int rating;
    std::cin>>rating;
    if (rating<=1399) std::cout<<"Division 4";
    else if (rating<=1599) std::cout<<"Dvision 3";
    else if (rating<=1899) std::cout<<"Dvision 2";
    else std::cout<<"Dvision 1";
    return 0;
}