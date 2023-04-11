#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");
int n,m;
vector<int>v(1001), g(1001);
vector<vector<int>>mem(1001, vector<int>(1001, -1));
int trova(int posv, int posg){
    if(posv >= n && posg >= m){
        return 0;
    }
    else if(posv >= n){
        return 0;
    }
    else if(posg >= m){
        return n-posv;
    }
    if(mem[posv][posg] != -1){
        return mem[posv][posg];
    }

    if(v[posv] >= g[posg]){
        mem[posv][posg] = max(trova(posv, posg+1), trova(posv+1, posg)+1);
    }
    else{
        mem[posv][posg] = max({trova(posv, posg+1), trova(posv+1, posg)+1, trova(posv+1, posg+1)+2});
    }
    return mem[posv][posg];
}

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    int t; fin >> t;
    for(int e=0; e<t; e++){
        v.clear(); g.clear(); mem.clear();
        v.resize(1001);
        g.resize(1001);
        mem.resize(1001, vector<int>(1001, -1));
        fin >> n >> m;
        for(int i=0; i<n; i++){
            fin >> v[i];
        }
        for(int i=0; i<m; i++){
            fin >> g[i];
        }
        fout << "Case #" << e+1 << ": " << trova(0, 0) << "\n";
    }
    return 0;
}