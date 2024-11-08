// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
vector<long long>fenwick;
long long sum(int x){
    long long sum = 0;
    while(x > 0){
        sum += fenwick[x];
        x -= x & -x;
    }
    return sum;
}
void update(int x, long long k){
    while(x < fenwick.size()){
        fenwick[x] += k;
        x += x & -x;
    }
}
struct zone{
    int l, r;
    long long k;
};
long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K){
    long long tot = 0;
    vector<zone> v(M);
    fenwick.resize(N+1);
    for(int i=0; i<N; i++)
        update(i+1, V[i]);
    for(int i=0; i<M; i++)
        v[i] = {L[i], R[i], K[i]};
    sort(v.begin(), v.end(), [](const zone a, const zone b){
        return a.r < b.r;
    });
    for(int i=0; i<M; i++){
        long long diff;
        zone a = v[i];
        
        if((diff = sum(a.r+1) - sum(a.l)) <= a.k)
            continue;
        else{
            update(a.r+1, -(diff - a.k));
            tot += diff - a.k;
        }
    }
    return tot;
}
#ifndef EVAL
int main(){
    int n, m; cin >> n >> m;
    vector<int> v(n), l, r;
    vector<long long> k;
    for(int &i : v)
        cin >> i;
    
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        l.push_back(a);
        r.push_back(b);
        k.push_back(c);
    }
    cout << alleggerisci(n, m, v, l, r, k);
}
#endif