// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

class tipo{
    public:
        long long x;
        long long y;
        long long z;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n, m, t; cin >> n >> m >> t;
    vector<vector<tipo>>v(n);
    for(long long i=0; i<m; i++){
        long long t, t1, t2, t3;
        cin >> t >> t1 >> t2 >> t3;
        tipo s; s.x = t1; s.y = t2; s.z = t3;
        v[t].push_back(s);
    }
    vector<long long>p(n, (long long)10e9);
    p[0] = 0;
    queue<long long>q; q.push(0);
    while(!q.empty()){
        long long pos = q.front();
        q.pop();
        for(auto i : v[pos]){
            if(i.z && p[pos]+i.y <= t && p[i.x] > p[pos]+i.y){
                p[i.x] = p[pos]+i.y;
                q.push(i.x);
            }
            else if(!i.z && p[i.x] > p[pos]+i.y){
                p[i.x] = p[pos]+i.y;
                q.push(i.x);
            }
        }
    }
    if(p[n-1] == (long long)(10e9)){
        cout << -1;
    }
    else{
        cout << p[n-1];
    }
    return 0;
}