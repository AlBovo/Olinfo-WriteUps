// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
vector<bool> vis;
vector<int> h;
void visita(int pos){
    if(vis[pos]) return;
    vis[pos] = true;
    if(pos > 0){
        if(h[pos-1] < h[pos]) visita(pos - 1);
    }
    if(pos < vis.size()-1){
        if(h[pos+1] < h[pos]) visita(pos + 1);
    }
}
int pollice_verde(int N, vector<int> H){
    vis.resize(N, false); h = H;
    vector<pair<int, int>>v;
    for(int i=0; i<N; i++) v.push_back({H[i], i});
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int tot = 0;
    for(int i=0; i<N; i++){
        if(!vis[v[i].second]){
            tot++;
            visita(v[i].second);
        }
    }
    return tot;
}
#ifndef EVAL
int main(){
    int n; cin >> n;
    vector<int>v(n);
    for(int &i:v) cin >> i;
    cout << pollice_verde(n, v);
    return 0;
}
#endif