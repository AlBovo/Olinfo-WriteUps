// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v, rev;
vector<bool>vis;
stack<int>kys;
void dfs(int pos, bool a){
    vis[pos] = true;
    for(int i : a ? v[pos] : rev[pos]){
        if(!vis[i])
            dfs(i, a);
    }
    if(a)
        kys.push(pos);
}
int find(int pos){
    vis[pos] = true;
    int tot = 1;
    for(int i : rev[pos]){
        if(!vis[i])
            tot += find(i);
    }
    return tot;
}
int paper(int N, int M, int A[], int B[]){
    v.resize(N); rev.resize(N);
    vis.resize(N, false);
    for(int i=0; i<M; i++){
        v[A[i]-1].push_back(B[i]-1);
        rev[B[i]-1].push_back(A[i]-1);
    }
    for(int i=0; i<N; i++)
        if(!vis[i])
            dfs(i, true);
    vis.assign(N, false);
    dfs(kys.top(), true);
    for(bool i : vis)
        if(!i)
            return 0;
    vis.assign(N, false);
    return find(kys.top());
}
#ifndef EVAL
int main(){
    int n, m; cin >> n >> m;
    int a[m], b[m];
    for(int i=0; i<m; i++)
        cin >> a[i] >> b[i];
    cout << paper(n, m, a, b);
}
#endif