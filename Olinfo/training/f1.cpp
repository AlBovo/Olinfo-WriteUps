// Punti: 100.0
#include <iostream>
#include <string>
#pragma GCC optimize("O2")

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::pair<int, std::string>p2;
    p2.first = (int)10e8;
    int n; std::cin>> n;
    int so1 = 0, so2 = 0;
    for(int i=0; i<n; i++){
        int s; std::cin>> s;
        if(s < p2.first){
            p2.first = s;
            p2.second = "Hamilton";
        }
        so1 += s;
    }
    for(int i=0; i<n; i++){
        int s; std::cin>> s;
        if(s < p2.first){
            p2.first = s;
            p2.second = "Verstappen";
        }
        so2 += s;
    }
    if(so1 < so2){
        std::cout<< "Hamilton\n";
    }
    else{
        std::cout<< "Verstappen\n";
    }
    std::cout<< p2.second;
    return 0;
}
