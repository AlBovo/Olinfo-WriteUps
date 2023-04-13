#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<int>>v;
vector<bool>vis;
int n, m;
 
void dfs(int pos){
    for(int i:v[pos]){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n+1);
    vis.resize(n+1, false);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>vec;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vec.push_back(i);
            dfs(i);
        }
    }
    cout << vec.size()-1 << "\n";
    for(int i=1; i<vec.size(); i++){
        cout << vec[i-1] << " " << vec[i] << "\n";
    }
    return 0;
}