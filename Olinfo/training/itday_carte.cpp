// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int gioca(int N, int K, vector<vector<int>> M){
    int tot = 0, last = 0;
    priority_queue<pair<int, pair<int, int>>>pq;
    
    for(int i=0; i<N; i++){
        pq.push({M[i][0] * -1, {i, 0}});
    }
    while(!pq.empty()){
        auto posT = pq.top();
        pq.pop();
        if(posT.second.second < K-1)
            pq.push({M[posT.second.first][posT.second.second+1] * -1, {posT.second.first, posT.second.second+1}});
        if(posT.first * -1 > last){
            last = posT.first * -1;
            tot++;
        }
    }
    return tot;
}
#ifndef EVAL
int main() {
    int N; cin >> N;
    int K; cin >> K;
    vector<vector<int>> M(N, vector<int> (K));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> M[i][j];
        }
    }
    cout << gioca(N, K, M) << endl;
    return 0;
}
#endif