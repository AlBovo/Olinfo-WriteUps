// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n, m; fin >> n >> m;
    vector<vector<int>>v(n);
    vector<int>c(n), visited(n, 0);
    for(int i=0; i<n; i++){
        fin >> c[i];
    }
    for(int i=0; i<m; i++){
        int t, t1; fin >> t >> t1;
        v[t].push_back(t1);
        v[t1].push_back(t);
    }
    int tot = c[0];
    visited[0] = 1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int i:v[pos]){
            if(!visited[i]){
                q.push(i);
                tot += c[i];
                visited[i] = 1;
            }
        }
    }
    fout << tot;
    return 0;
}
