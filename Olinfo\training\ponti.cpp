// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<bool>vis;
vector<vector<int>>v;

void dfs(int pos){
    vis[pos] = true;
    for(int i:v[pos]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    int n, m; fin >> n >> m;
    v.resize(n);
    vis.resize(n, false);
    for(int i=0; i<m; i++){
        int a, b; fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int tot = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            tot++;
            dfs(i);
        }
    }
    fout << tot-1;
    return 0;
}