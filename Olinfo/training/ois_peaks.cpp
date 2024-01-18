// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    long long M; cin >> M;

    vector<long long>a(N+2, 0), b(M+2, 0);
    for(long long i=1; i<=N; i++) cin >> a[i];
    for(long long i=1; i<=M; i++) cin >> b[i];
    long long t = 0, tot = 0;
    for(long long i=1; i<=M; i++){
        if(b[i] > b[i-1] && b[i] > b[i+1]) t++;
    }
    for(long long i=1; i<=N; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]) tot += t;
    }

    cout << tot << "\n";
}