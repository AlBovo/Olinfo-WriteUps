#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<bool>>mat;
void dfs(int x, int y){
    mat[x][y] = false;
    if(mat[x+1][y]){
        dfs(x+1, y);
    }
    if(mat[x-1][y]){
        dfs(x-1, y);
    }
    if(mat[x][y+1]){
        dfs(x, y+1);
    }
    if(mat[x][y-1]){
        dfs(x, y-1);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    mat.resize(n+4, vector<bool>(m+4, false));
    vector<pair<int,int>>q;
    for(int i=2; i<=n+1; i++){
        for(int e=2; e<=m+1; e++){
            char t; cin >> t;
            mat[i][e] = (t == '.');
            if(mat[i][e]){
                q.push_back({i, e});
            }
        }
    }
    int tot = 0;
    for(auto i:q){
        if(mat[i.first][i.second]){
            dfs(i.first, i.second);
            tot++;
        }
    }
    cout << tot;
    return 0;
}