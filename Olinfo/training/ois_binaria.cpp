// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    long long tot = 0;
    for(int i=0; i<n; i++){
        long long v; cin >> v;
        if(__builtin_popcountll(v) == 1)
            tot += (__bit_ceil(v+1) - 1) - v;
        else
            tot += (__bit_ceil(v+1) - 1) - v;
    }
    cout << tot;
    return 0;
}