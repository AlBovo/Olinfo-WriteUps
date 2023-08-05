// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map<int, vector<int>>m;

void dfs(int pos){
    if(!m[pos].empty()){
        dfs(m[pos].back());
        m[pos].pop_back();
    }
}

int main(){
    int n, tot = 0; fin >> n;
    for(int i=0; i<n; i++){
        int t, t1; fin >> t >> t1;
        m[t].push_back(t1);
    }
    for(auto &i : m){
        for(int e : i.second){
            tot++;
            dfs(e);
        }
    }
    fout << tot;
    return 0;
}