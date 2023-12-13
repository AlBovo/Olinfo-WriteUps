// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>>v;
vector<bool>vis;
// true non ci sono componenti sconnesse
void dfs(int pos, int m){
    if(vis[pos]) return;
    vis[pos] = true;
    for(auto i : v[pos]){
        if(i.second < m) continue;
        dfs(i.first, m);
    }
}
bool isDone(){
    for(bool i:vis){
        if(!i) return false;
    }
    return true;
}

int main(){
    int n, q, maxi = -1; cin >> n >> q;
    v.resize(n);
    for(int i=0; i<q; i++){
        int a, b, r; cin >> a >> b >> r;
        v[a].push_back({b, r});
        v[b].push_back({a, r});
        maxi = max(maxi, r);
    }

    int l = 0, r = maxi + 1;
    while(l+1 < r){
        vis = vector<bool>(n, false);
        int m = l + (r - l) / 2;
        // cout << m << " ";
        dfs(0, m);
        if(isDone()){
            l = m;
        }
        else{
            r = m;
        }
    }
    cout << l << "\n";
    return 0;
}