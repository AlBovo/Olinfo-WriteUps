// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<int>>v; // 0 non preso, 1 preso
int maxi = 0, n, m;

void trova(int me, int u, pair<int,int>i){
    if(i.first >= n+3 || i.second >= m + 3){
        maxi = max(me, maxi);
        return;
    }
    if(me + (u*13+13)/16 <= maxi){ return; } // lamerata
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
    int u; fin >> n >> m; u = n*m;
    v.resize(n+7, vector<int>(m+7, 0));
    trova(0, u, {3, 3});
    cout << maxi;
    return 0;
}