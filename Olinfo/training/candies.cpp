// Punti: 100.0
#include<vector>
#include<iostream>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);//
    long long N, bin = 1, tot = 1;
    std::cin >> N;
    std::vector<long long>V(N);
    for(long long &i : V){
        std::cin >> i;
    }
    std::sort(V.begin(), V.end());

    for(long long i = 1; i < N; i++){
        if(V[i] != V[i-1]){
            bin++;
        }
        tot += bin;
    }
    std::cout << tot;
    return 0;
}
