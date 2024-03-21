// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
long long solve(long long n){
    if(n == 1) return 1;
    return (n - (n & (1LL << (63 - __builtin_clzll(n))))) * 2 + 1;
}
int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        long long n; cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}