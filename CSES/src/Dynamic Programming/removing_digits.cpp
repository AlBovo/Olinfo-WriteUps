#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
vector<int>dp((int)1e6+1, -1);
 
int find(string s, int t){
    //cout << s << " ";
    if(dp[t] != -1 ){ return dp[t]; }
    if(s.size() == 1 && t > 9){ return 1e9; }
    int mini = 1e9, f;
    for(char i : s){
        if(i == '0'){ continue; }
        f = (i - 48);
        if(f > t){ continue; }
        if(f == t){ return 1; }
        mini = min(mini, find(to_string(t - f), t - f) + 1);
    }
    dp[t] = mini;
    return mini;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    cout << find(to_string(n), n);
    return 0;
}