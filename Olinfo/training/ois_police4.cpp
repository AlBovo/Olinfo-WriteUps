// Punti: 65.0
#include<bits/stdc++.h>
using namespace std;
int n, r, t, l;
vector<int>v;
vector<vector<unordered_map<int, int>>>dp;
// [v_i][r][POS]

bool status(int N){
    return (int)(N / t) % 2 == 0; // True = Green, False = Red
}

int fdp(int pos, int res, int tim){
    if(pos == n)
        return 0;
    if(dp[pos][res].count(tim))
        return dp[pos][res][tim];

    int dist = ((pos == n - 1) ? l : v[pos+1]) - v[pos];
    if(status(tim)){
        return dp[pos][res][tim] = (fdp(pos + 1, res, tim + dist) + dist);
    }
    else{
        int next = ((int)(tim / t) + 1) * t;
        int choice = fdp(pos + 1, res, next + dist) + (next - tim);
        if(res > 0)
            choice = min(choice, fdp(pos + 1, res - 1, tim + dist));
        return dp[pos][res][tim] = (choice + dist);
    }
}

int main(){
    cin >> n >> r >> t >> l; 
    v.resize(n);
    dp.resize(n, vector<unordered_map<int, int>>(r+1));
    for(int &i : v) cin >> i;
    cout << fdp(0, r, v[0]) + v[0];
    return 0;
}