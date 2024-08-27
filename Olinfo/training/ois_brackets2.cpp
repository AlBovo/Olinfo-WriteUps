// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int n, maxsize = 50000*2;
vector<int>A;
vector<bool>risp;
vector<vector<int>>dp;

int solve(int pos, int sum){
    if(pos == n){
        if(sum == 0)
            return dp[pos][sum] = 1;
        return dp[pos][sum] = 0;
    }
    if(dp[pos][sum] != -1)
        return dp[pos][sum];
    risp[pos] = true;
    if(solve(pos + 1, sum + A[pos]) == 1)
        return dp[pos][sum] = 1;
    risp[pos] = false;
    if(sum - A[pos] >= 0)
        if(solve(pos + 1, sum - A[pos]) == 1)
            return dp[pos][sum] = 1;
    return dp[pos][sum] = 0;
}

int main(){
    cin >> n;
    A.resize(n);
    risp.resize(n);
    dp.resize(n + 1, vector<int>(maxsize, -1));
    for(int &i : A)
        cin >> i;

    if(solve(0, 0) == 0)
        cout << -1;
    else
        for(int i=0; i<n; i++)
            cout << string(A[i], risp[i] ? '(' : ')'); 
    return 0;
}