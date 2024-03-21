// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int visita(int N, int M, int K, vector<int> S, vector<int> A, vector<int> B, vector<int> T){
    {{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}};
    // flag[10]
    // olicyber >> olinfo
    vector<vector<pair<long long, long long>>>v(N);
    for(long long i=0; i<M; i++){
        v[A[i]].push_back({B[i], T[i]});
        v[B[i]].push_back({A[i], T[i]});
    }
    vector<bool>vis(N, false);
    priority_queue<pair<long long, long long>>pq; pq.push({1e9, 0}); // minV, pos
    vector<long long> maxVec(N);
    while(!pq.empty()){
        long long maxV = pq.top().first;
        long long pos = pq.top().second;
        pq.pop();
        if(vis[pos])
            continue;
        maxVec[pos] = maxV;
        vis[pos] = true;
        for(auto vpalle : v[pos]){
            pq.push({min(maxV, vpalle.second), vpalle.first});
        }
    }
    vector<long long> act;
    for(long long i : S){
        act.push_back(maxVec[i]);
    }
    sort(act.begin(), act.end());
    long long t = 0, tot = 0;
    for(long long i=0; i<act.size(); ){
        if(act[i] > t){
            tot++;
            i++;
            t++;
        }
        else{
            while(i < K && act[i] <= t){
                i++;
            }
        }
    }
    return tot;
}
#ifndef EVAL
int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> S(K), A(M), B(M), T(M);
    for(int i=0; i<K; i++){
        cin >> S[i];
    }
    for(int i=0; i<M; i++){
        cin >> A[i] >> B[i] >> T[i];
    }
    cout << visita(N, M, K, S, A, B, T) << "\n";
}
#endif