#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    vector<int>team(n);
    vector<bool>visited(n, false);
    vector<vector<int>>v(n);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
 
    queue<int>q;
    for(int i=0; i<n; i++){
        if(visited[i])
            continue;
        team[i] = 1;
        q.push(i);
        while(!q.empty()){
            int pos = q.front();
            visited[pos] = true;
            q.pop();
            for(int e : v[pos]){
                if(team[e] == team[pos]){
                    cout << "IMPOSSIBLE";
                    return 0;
                }
                if(visited[e])
                    continue;
                team[e] = (team[pos] == 1)? 2 : 1;
                q.push(e);
            }
        }
    }
    for(int i : team){
        cout << i << " ";
    }
    return 0;
}