// Punti: 15.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int longMax = -1, l;
int a = -1, b = -1, c = -1;
vector<vector<int>> mat;
vector<bool> vis;
void dfs(int pos, int lung){
    if(vis[pos]) return;
    if(lung > longMax && pos != a && pos != b){
        longMax = lung;
        l = pos;
    }
    vis[pos] = true;
    for(int &i:mat[pos]){
        dfs(i, lung + 1);
    }
}
void dfs2(int pos, int lung){ // dfs from c to a
    if(vis[pos] || vis[a]) return;
    vis[pos] = true;
    if(pos == a){
        longMax = lung;
        return;
    }
    for(int &i:mat[pos]){
        dfs2(i, lung + 1);
    }
}
int build(int N, vector<int> A, vector<int> B){
    int tot = 0;
    mat.resize(N);
    for(int i=0; i<A.size(); i++){
        mat[A[i]].push_back(B[i]);
        mat[B[i]].push_back(A[i]);
    }
    vis.resize(N, false);
    dfs(0, 0);
    //cout << l << " "; // a
    a = l; longMax = -1;
    vis.clear();
    vis.resize(N, false);
    dfs(a, 0);
    //cout << l << " "; // b
    b = l; tot += longMax; longMax = -1;
    vis.clear();
    vis.resize(N, false);
    dfs(b, 0);
    //cout << l << " "; // c
    c = l;
    tot += longMax;
    longMax = -1;
    vis.clear();
    vis.resize(N, false);
    dfs2(c, 0);
    //cout << "peso a-c: " << longMax << "\n";
    return tot + longMax;
}
#ifndef EVAL
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    cout << build(n, a, b);
    return 0;
}
#endif