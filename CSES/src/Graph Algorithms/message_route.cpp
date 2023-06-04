#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>>v(n+1);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<pair<long long, int>>p(n+1, {(long long)1e18, 0});
    queue<int>q;
    q.push(1);
    p[1] = {0, 0};
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        for(int i:v[pos]){
            if(p[pos].first+1 < p[i].first){
                p[i].first = p[pos].first+1;
                p[i].second = pos;
                q.push(i);
            }
        }
    }
    if(p[n].first == (long long)1e18){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int>l;
        int pos = n;
        while(pos != 0){
            l.push_back(pos);
            pos = p[pos].second;
        }
        cout << l.size() << "\n";
        reverse(l.begin(), l.end());
        for(int i:l){
            cout << i << " ";
        }
    }
    return 0;
}