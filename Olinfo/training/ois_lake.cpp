// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<char, bool>>>v;
long long dfs(int x, int y){
    if(v[x][y].second) return 0;
    if(v[x][y].first != '#') return 0;
    v[x][y].second = true;
    long long tot = (v[x+1][y].first == '.') + (v[x-1][y].first == '.') +
                    (v[x][y+1].first == '.') + (v[x][y-1].first == '.');
    return tot + dfs(x+1, y) + dfs(x-1, y) + dfs(x, y+1) + dfs(x, y-1);
}
int main(){
    int n, m; cin >> n >> m;
    v.resize(n+2, vector<pair<char, bool>>(m+2, {'.', false}));
    int x = -1, y = -1;
    for(int i=1; i<=n; i++){
        for(int e=1; e<=m; e++){
            cin >> v[i][e].first;
            if(v[i][e].first == '#'){
                x = i; y = e;
            }
        }
    }
    cout << dfs(x,y);
    return 0;
}