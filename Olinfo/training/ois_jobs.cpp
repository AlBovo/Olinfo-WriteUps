// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>>v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i].first;
    for (int i = 0; i < n; ++i)
        cin >> v[i].second;
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) -> bool { return a.second * (long long) b.first < a.first * (long long) b.second; });
    long long ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += v[i].first;
    while (m - v.back().first >= sum)
    {
        ans += v.back().second;
        m -= v.back().first;
    }
    vector<long long> dp(m + 1, 0ll);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = v[i - 1].first; j <= m; ++j)
        {
            dp[j] = max(dp[j], dp[j - v[i - 1].first] + v[i - 1].second);
        }
    }
    cout << ans + dp.back() << endl;
}