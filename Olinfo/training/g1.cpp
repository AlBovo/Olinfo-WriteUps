// Punti: 100.0
#include <iostream>
#include <vector>
#pragma GCC optimize("O2")

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    long long n, m; std::cin >> n >> m;
    std::vector<long long>v(n), s(n), ma(n);
    std::pair<long long,long long>p = {-1, -1};
    for(long long i=0; i<n; i++){
        long long t; std::cin >> t;
        v[t] = i;
        s[i] = t;
    }
    for(long long i=0; i<m; i++){
        long long t; std::cin >> t;
        long long pos = v[t];
        v[s[pos-1]]++;
        v[s[pos]]--;
        t = s[pos-1];
        s[pos-1] = s[pos];
        s[pos] = t;
        ma[s[pos]]++;
        if(ma[s[pos]] > p.first){
            p.first = ma[s[pos]];
            p.second = s[pos];
        }
        else if(ma[s[pos]] == p.first && s[pos] < p.second){
            p.first = ma[s[pos]];
            p.second = s[pos];
        }
        std::cout << p.second << "\n";
    }
    return 0;
}
