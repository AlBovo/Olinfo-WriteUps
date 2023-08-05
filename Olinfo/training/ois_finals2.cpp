// Punti: 100.0
#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    int maxi = 0, tot = 0, temp, n, m, r; std::cin >> n >> m;
    for(int i=0; i<n; i++){
        if(!i){
            for(int e=0; e<3; e++){
                std::cin >> temp;
                tot += temp;
            }
        }
        else{
            r = 0;
            for(int e=0; e<3; e++){
                std::cin >> temp;
                r += temp;
            }
            maxi = std::max(maxi, r+m*100);
        }
    }
    if(tot > maxi){
        std::cout << 0;
    }
    else{
        std::cout << maxi-tot+1;
    }
    return 0;
}
