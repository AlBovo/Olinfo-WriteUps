// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<bool>>v; // 0 non preso, 1 preso
int maxi = -1, n, m;

void trova(int me, int u, pair<int,int>i){
    if(i.first >= n+3 || i.second >= m + 3){
        maxi = max(me, maxi);
        return;
    }
    if(me + (u*13+13)/16 <= maxi){ return; } // lamerata
    if(v[i.first][i.second]){
        if(i.second + 1 == m+3){ 
            trova(me, u, {i.first+1, 3});
        }
        else{
            trova(me, u, {i.first, i.second+1});
        }
        return;
    }
    v[i.first][i.second] = 0;
    if(i.second + 1 == m+3){
        trova(me, u-1, {i.first+1, 3});
    }
    else{
        trova(me, u-1, {i.first, i.second+1});
    }
    if((!v[i.first][i.second-2] || !v[i.first][i.second-1]) &&
    (!v[i.first][i.second+1] || !v[i.first][i.second+2]) &&
    (!v[i.first][i.second-1] || !v[i.first][i.second+1]) &&
    (!v[i.first-2][i.second] || !v[i.first-1][i.second]) &&
    (!v[i.first-1][i.second] || !v[i.first+1][i.second]) &&
    (!v[i.first+2][i.second] || !v[i.first+1][i.second]) &&
    (!v[i.first+2][i.second-2] || !v[i.first+1][i.second-1]) &&
    (!v[i.first+1][i.second-1] || !v[i.first-1][i.second+1]) &&
    (!v[i.first-2][i.second+2] || !v[i.first-1][i.second+1]) &&
    (!v[i.first-2][i.second-2] || !v[i.first-1][i.second-1]) &&
    (!v[i.first-1][i.second-1] || !v[i.first+1][i.second+1]) &&
    (!v[i.first+1][i.second+1] || !v[i.first+2][i.second+2])
    ){ // che schifo di codice
        v[i.first][i.second] = 1;
        if(i.second + 1 == m+3){
            trova(me+1, u-1, {i.first+1, 3});
        }
        else{
            trova(me+1, u-1, {i.first, i.second+1});
        }
    }
    v[i.first][i.second] = 0;
}

int main(){
    int u = 0, t; fin >> n >> m;
    v.resize(n+7, vector<bool>(m+7, 0));
    for(int i=3; i<n+3; i++){
        for(int e=3; e<m+3; e++){
            fin >> t;
            v[i][e] = (t == 1);
            if(!v[i][e]){
                u++;
            }
        }
    }
    trova(0, u, {3, 3});
    cout << maxi;
    return 0;
}