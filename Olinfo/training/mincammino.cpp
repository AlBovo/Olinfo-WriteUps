// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optmize("Ofast")
using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int>& D){
    vector<vector<pair<int, int>>>v(N);
    D.assign(N, (int)1e9);
    D[0] = 0;
    for(int i=0; i<M; i++){
        v[X[i]].push_back({Y[i], P[i]});
    }
    priority_queue<pair<int, int>>q;
    vector<bool>vis(N);
    q.push({0, 0});
    while(!q.empty()){
        auto pos = q.top().second;
        q.pop();
        if(vis[pos]){ continue; }
        vis[pos] = true;
        for(auto &i:v[pos]){
            if(D[pos] + i.second < D[i.first]){
                D[i.first] = D[pos] + i.second;
                q.push({D[i.first]*-1, i.first});
            }
        }
    }
    for(int &i:D){
        if(i == (int)1e9){ i = -1; }
    }
}