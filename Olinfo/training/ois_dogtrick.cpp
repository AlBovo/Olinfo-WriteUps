// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K; cin >> N >> K;

    vector<int> v(N);
    for (int& i : v)
        cin >> i;
    
    int M; cin >> M;
    
    vector<set<int>> prec(K + 2);
    while (M--){
        int a, b; cin >> a >> b;
        prec[b].insert(a);
    }

    for (int i = 1; i < K + 1; ++i)
        prec[i].insert(-1);

    v.insert(v.begin(), -1);
    v.insert(v.begin(), -1);
    vector<int> dp(N + 2, -1);
    dp[0] = dp[1] = 0;

    for (int i = 2; i < N + 2; ++i){
        if (dp[i - 1] != -1 && prec[v[i]].count(v[i - 1]))
            dp[i] = max(dp[i], dp[i - 1] + 1);
        if (dp[i - 2] != -1 && prec[v[i]].count(v[i - 2]))
            dp[i] = max(dp[i], dp[i - 2] + 1);
    }

    int ans = max(dp[N + 1], dp[N]);
    if (ans == -1)
        cout << 0;
    else
        cout << ans;
}