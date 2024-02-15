// Punti: 51.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<short> boh(N);
    vector<short> ans(N);
    int start = N;
    auto dfs = [&](int i, int p, auto dfs) -> void
    {
        boh[--start] = i;
        if (start + K >= N)
            ans[i] = -1;
        else
            ans[i] = boh[start + K];
        for (auto &c : v[i])
            if (c != p)
                dfs(c, i, dfs);
        ++start;
    };
    dfs(0, -1, dfs);
    for (auto &i : ans)
        cout << i<< " ";
}