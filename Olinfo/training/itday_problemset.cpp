// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;
//eliasus
vector<int> bilancia(int N, int M, vector<vector<int>> S) {
    unordered_map<int, pair<int, int>> m;
    vector<bool>vv(M+1, false);
    for(auto i : S){
        for(int e : i){
            vv[e] = true;
            if(!m.count(e))
                m[e] = {1, e};
            else
                m[e] = {m[e].first + 1, e};
        }
    }
    vector<pair<int, int>>risp;
    for(auto i : m){
        risp.push_back(i.second);
    }
    sort(risp.begin(), risp.end(), greater<pair<int, int>>());
    for(int i=0; i<N; i++){
        vector<bool>rs(M, false);
        int minx = 1e9;
        for(int e : S[i]){
            minx = min(minx, (m.count(e) ? m[e].first : 0));
            rs[e] = true;
        }
        for(int e=0; e<risp.size(); e++){
            if(rs[risp[e].second]) continue;
            if(risp[e].first >= minx)
                return {};
            else
                break;
        }
    }
    vector<int>res;
    for(int i=0; i<risp.size(); i++){
        res.push_back(risp[i].second);
    }
    for(int i=0; i<M; i++){
        if(!vv[i]) res.push_back(i);
    }
    return res;
}

// NON TOCCARE SOTTO QUESTA LINEA

#ifndef EVAL

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> S(N);

    for (vector<int>& i : S) {
        int size;
        cin >> size;
        i.resize(size);
        for (int& j : i)
            cin >> j;
    }

    vector<int> ans = bilancia(N, M, S);

    if (ans.size() == 0)
        cout << "IMPOSSIBLE";
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}

#endif
