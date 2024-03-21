// Punti: 50.0
#include<bits/stdc++.h>
using namespace std;
const int MODULO = 1000000007;
unordered_map<int, int>dp; // forse
int fastExp(long long x, int y){ 
    int res = 1;
    x = x % MODULO;
    if (x == 0) return 0;
    while (y > 0){ 
        if (y & 1) 
            res = (res*x) % MODULO; 
 
        y >>= 1;
        x = (x*x) % MODULO; 
    } 
    return res; 
} 
vector<int> execute(int N, int K, int D, vector<int> A){
    vector<int>b(N, 1);
    if(D == 0){
        for(int i=0; i<N; i++){
            b[i] = fastExp(A[i], K);
        }
        return b;
    }
    int cyclic = lcm(N, D) / D;
    for(int i=0; i<N; i++){
        long long k = 1, pos = i;
        for(int e=0; e<min(cyclic, K); e++){
            k = ((k % MODULO) * (A[pos] % MODULO)) % MODULO;
            pos -= D;
            pos = (N + (pos % N)) % N;
        }
        if(cyclic < K){
            if(dp.count(k))
                b[i] = dp[k];
            else
                b[i] = dp[k] = fastExp(k, K / cyclic);
            k = 1, pos = i;
            for(int e=0; e<K - cyclic * (K / cyclic); e++){
                k = ((k % MODULO) * (A[pos] % MODULO)) % MODULO;
                pos -= D;
                pos = (N + (pos % N)) % N;
            }
            b[i] = (b[i] * k) % MODULO;
        }
        else{
            b[i] = k;
        }
    }
    return b;
}
#ifndef EVAL
int main() {
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> A(N);
    for (int& x : A) cin >> x;
    vector<int> B = execute(N, K, D, A);
    for (size_t i = 0; i < B.size(); ++i) {
        cout << B[i];
        if (i + 1 < B.size()) cout << " ";
    }
    cout << endl;
}
#endif