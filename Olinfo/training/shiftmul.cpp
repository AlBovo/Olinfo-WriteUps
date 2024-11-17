// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
const int MODULO = 1000000007;
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
int modulo_neg(long long val, int n){
    return ((val % n) + n) % n;
}
vector<int> execute(int N, int K, int D, vector<int> A){
    if(D == 0){
        vector<int>b(N, 1);
        for(int i=0; i<N; i++){
            b[i] = fastExp(A[i], K);
        }
        return b;
    }
    if(K == 0)
        return vector<int>(N, 1);
    auto k_2 = execute(N, K/2, D, A);
    auto k_3 = k_2;
    for(int i=0; i<N; i++)
        k_2[i] = ((long long)k_3[i] * k_3[modulo_neg(i - ((long long)D * (K/2)), N)]) % MODULO;
    
    if(K % 2 != 0)
        for(int i=0; i<N; i++)
            k_2[i] = ((long long)k_2[i] * A[modulo_neg(i - ((long long)D * (K - 1)), N)]) % MODULO;
    return k_2;
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
    return 0;
}
#endif