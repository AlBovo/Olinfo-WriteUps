// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int n, m, tot = 0, f = 0;
vector<bool>fatti;
vector<vector<int>>v;
void dfs(int nodo){
    if(fatti[nodo]){
        return;
    }
    else{
        fatti[nodo] = true;
        f = 1;
        for(int i : v[nodo]){
            dfs(i);
        }
    }
}

int main(){
    fin >> n >> m;
    v.resize(n); fatti.resize(n);
    for(int i=0; i<m; i++){
        int t, t1; fin >> t >> t1;
        v[t].push_back(t1);
        v[t1].push_back(t);
    }
    for(int i=0; i<n; i++){
        dfs(i);
        if(f){
            f = 0;
            tot++;
        }
    }
    fout << tot-1;
    return 0;
}