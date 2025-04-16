// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++){
        if(P[i] == i) continue;
        if(P[P[i]] != i){
            cout << "NO\n";
            return 0;
        }
        if(P[i] > i)
            v.push_back({i, P[i]});
    }
    sort(v.begin(), v.end());
    vector<vector<int>>vv;
    vector<bool>pr(v.size(), false);
    pair<int, int>p;
    vector<int>vp;
    for(int i=0; i<v.size(); i++){
        if(i > 0 && pr[i]) continue;
        p = v[i];
        vp = {p.first, p.second};
        for(int e=i+1; e<v.size(); e++){
            if(v[e].first > p.first && v[e].second < p.second) {
                if(pr[e]) continue;
                vp.push_back(v[e].first);
                vp.push_back(v[e].second);
                p = v[e];
                pr[e] = true;
            }
            else if(v[e].first > p.second) {
                vv.push_back(vp);
                vp = {};
                break;
            }
        }
        if(vp.size() > 0){
            vv.push_back(vp);
            vp = {};
        }
    }
    if(vp.size() > 0){
        vv.push_back(vp);
    }
    cout << "YES\n";
    cout << vv.size() << "\n";
    for(auto &i : vv){
        cout << i.size() << " ";
        for(auto e : i)
            cout << e << " ";
        cout << "\n";
    }
    return 0;
}
