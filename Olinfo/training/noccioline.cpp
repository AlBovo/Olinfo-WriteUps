// Punti: 100.0
#include<bits/stdc++.h>
#include <assert.h>
using namespace std;

int ContaOperazioni(int N, int K, int* secchi){
    int tolti = 0, messi = 0;
    for(int i=0; i<N; i++){
        if(secchi[i] > K)
            tolti += secchi[i] - K;
        else
            messi += K - secchi[i]; 
    }
    // cout << K << " " << messi << " " << tolti << "\n";
    return max(messi, tolti);
}

#ifndef EVAL
int main(){
    int n, k; cin >> n >> k;
    int secchi[n];
    for(int i=0; i<n; i++){
        cin >> secchi[i];
    }
    cout << ContaOperazioni(n, k, secchi);
    return 0;
}
#endif