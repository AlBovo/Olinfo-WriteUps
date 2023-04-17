// Punti: 100.0
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long T;
    std::cin >> T;
    for(long long t = 0; t < T; t++){
        long long N, Q, tot = 0, bin;
        bool hack = false;
        std::cin >> N >> Q;
        std::vector<long long> V(N);
        for(long long &i : V){
            std::cin >> i;
        }
        for(long long i = 0; i < Q; i++){
            std::cin >> bin;
            if(bin >= 0){
                tot += bin;
            }
            else{
                tot -= V[std::abs(bin)-1];
                if(tot < 0 && !hack){
                    std::cout << "HACKER\n";
                    hack = true;
                }
            }
        }
        if(!hack){
            std::cout << "OK\n";
        }
        hack = false;
    }
    return 0;
}
