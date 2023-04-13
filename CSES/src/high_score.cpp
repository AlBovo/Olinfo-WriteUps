#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int dfs(int pos){
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n, m; cin >> n >> m;
    vector<vector<pair<long long, long long>>>v(n+1);
    for(long long i=0; i<m; i++){
        long long a,b,c; cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    queue<long long>q;
    q.push(1);
    vector<long long>p(n+1, -1e18);
    vector<long long>volte(n+1, 0);
    p[1] = 0;
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        for(auto i:v[pos]){
            if(p[pos]+i.second > p[i.first] && volte[i.first] < n+2){
                q.push(i.first);
                p[i.first] = p[pos]+i.second;
                volte[i.first]++;
            }
        }
    }
    vector<int>vis(n+1, 0);
    function<bool(int, bool)> boh = [&](int pos, bool trov)->bool{
        if(pos == n && trov){
            return true;
        }
        if(vis[pos] != 0){
            return vis[pos] == 1;
        }
        vis[pos] = -1;
        for(auto i:v[pos]){
            if(boh(i.first, trov || (volte[i.first] >= n))){
                vis[pos] = 1;
                return true;
            }
        }
        return false;
    };
    if(boh(1, volte[1]>=n)){
        cout << -1;
    }
    else{
        cout << p[n];
    }
    return 0;
}