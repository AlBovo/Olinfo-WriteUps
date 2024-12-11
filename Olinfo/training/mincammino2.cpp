// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D){
    D = vector<long long>(N, 1e18);
    vector<vector<pair<int, long long>>>v(N);
    for(int i=0; i<M; i++)
        v[X[i]].push_back({Y[i], P[i]});
    vector<bool>vis(N, false);
    priority_queue<pair<long long, int>>pq; // -cost, pos
    pq.push({0, 0});
    D[0] = 0;
    while(!pq.empty()){
        auto [cost, pos] = pq.top();
        pq.pop();
        if(vis[pos])
            continue;
        vis[pos] = true;
        for(auto i : v[pos]){
            if(D[pos] + i.second < D[i.first]){
                D[i.first] = D[pos] + i.second;
                pq.push({D[i.first]*-1, i.first});
            }
        }
    }
    for(int i=0; i<N; i++)
        D[i] = (D[i] == (long long)1e18) ? -1 : D[i];
}
#ifndef EVAL
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), P(M);
    vector<long long> D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }
    mincammino(N, M, X, Y, P, D);
    for (int i = 0; i < N; i++) {
        cout << D[i] << ' ';
    }
    cout << '\n';
}
#endif