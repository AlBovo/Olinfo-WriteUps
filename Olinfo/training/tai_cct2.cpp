// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int fast_exp(int b, int e, int p){
    if(e == 0) return 1;
    if(e == 1) return b % p;
    int f = fast_exp(b, e/2, p) % p;
    if(e % 2)
        return ((f * f) % p * (b % p)) % p;
    return (f * f) % p;
}
int speedrunna(int N, int K, int a, int b){
    vector<int> vecchi(K+1, 1e9), nuovi(K+1, 1e9);
    vecchi[1] = 1;
    for(int i=1; i<N; i++){
        int exp = fast_exp(b, i, K);
        int exp2 = fast_exp(a, i, 1000);
        nuovi.assign(K+1, 1e9);
        for(int k=0; k<=K; k++){
            int f = min(K, k + exp);
            nuovi[f] = min(nuovi[f], vecchi[k] + exp2);
        }
        nuovi[0] = vecchi[K];
        swap(vecchi, nuovi);
    }
    int less = 1e9;
    for(int i=0; i<=K; i++)
        less = min(less, vecchi[i]);
    return less;
}
#ifndef EVAL
int main(){
    int N, K, a, b;
    cin >> N >> K >> a >> b;
    cout << speedrunna(N, K, a, b);
    return 0;
}
#endif