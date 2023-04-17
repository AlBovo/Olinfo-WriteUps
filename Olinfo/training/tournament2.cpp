// Punti: 100.0
#include <algorithm>
#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; std::cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c, sum = 0;
        std::cin >> a >> b >> c;
        for(int e=0; e<a; e++){
            int t; std::cin >> t;
            sum += t;
        }
        if((int)(sum/a)+1 > b+c){
            std::cout << "Cheater\n";
        }
        else{
            std::cout << "Innocent\n";
        }
    }
    return 0;
}
