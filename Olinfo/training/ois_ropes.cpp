// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int, int>>v(n+1, {0, 0});
    {
        vector<int>p(n);
        for(int &i : p) cin >> i;
        for(int i=0; i<n; i++){
            int t; cin >> t;
            v[p[i]].first += t;
            v[p[i]].second = max(v[p[i]].second, t);
        }
    }
    int tot = 0;
    for(int i=0; i<n+1; i++){
        tot += v[i].first - v[i].second;
    }
    cout << tot;
    return 0;
}