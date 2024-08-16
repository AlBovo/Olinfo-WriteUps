// Punti: 29.0
#include<bits/stdc++.h>
using namespace std;

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C){
    vector<vector<pair<int, int>>>v(N);
    vector<bool>vis(N, false);
    for(int i=0; i<M; i++){
        v[arco_da[i]-1].push_back({arco_a[i]-1, capacita[i]});
        v[arco_a[i]-1].push_back({arco_da[i]-1, capacita[i]});
    }

    priority_queue<pair<int, pair<int, int>>>q;
    q.push({(int)(1e9), {W-1, 0}}); // min, {pos, tot}
    bool done = false;
    int mini = 1e9, mini2 = 1e9;

    while(!q.empty()){
        auto pos = q.top();
        q.pop();
        if(vis[pos.second.first])
            continue;
        if(done && pos.first > mini)
            continue;

        if(pos.second.first == L-1){
            done = true;
            mini = min(mini, pos.second.second);
            mini2 = min(mini2, pos.first);
            continue;
        }
        vis[pos.second.first] = true;
        for(auto i : v[pos.second.first]){
            q.push({min(pos.first, i.second), {i.first, pos.second.second + 1}});
        }
    }
    return mini2;
}

#ifndef EVAL
int main(){
    int n, m, w, l, r, c;
    cin >> n >> m >> w >> l >> r >> c;
    int arco_da[m], arco_a[m], capacita[m];
    for(int i=0; i<m; i++){
        cin >> arco_da[i] >> arco_a[i] >> capacita[i];
    }
    cout << Analizza(n, m, w, l, arco_da, arco_a, capacita, r, c);
    return 0;
}
#endif