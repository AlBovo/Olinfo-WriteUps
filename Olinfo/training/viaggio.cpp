#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n, m; fin >> n >> m;
    vector<vector<pair<int, int>>>ad(n+1);
    for(int i=0; i<m; i++){
        int t, t1, t2;
        fin >> t >> t1 >> t2;
        ad[t].push_back({t1, t2});
        ad[t1].push_back({t, t2});
    }
    queue<int>q;
    vector<int>p(n+1, 10e8);
    q.push(1);
    p[1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : ad[v]){
            if(p[v]+i.second < p[i.first]){
                p[i.first] = p[v]+i.second;
                q.push(i.first);
            }
        }
    }
    cout << p[n];
    return 0;
}