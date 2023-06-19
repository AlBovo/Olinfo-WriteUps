#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;

#define MOD (int)(1e9+7)

int n;
vector<vector<bool>>m;
vector<vector<long long>>dp;

long long dfs(int x, int y){
	if(x >= n || y >= n || x < 0 || y < 0) return 0;
	if(m[x][y]) return 0;
	if(x == n-1 && y == n-1) return 1;
	if(dp[x][y] != -1) return dp[x][y] % MOD;
	dp[x][y] = (dfs(x+1, y) % MOD + dfs(x, y+1) % MOD) % MOD;
	return dp[x][y];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp.resize(n+1, vector<long long>(n+1, -1));
	m.resize(n+1, vector<bool>(n+1, false));
	for(int i=0; i<n; i++){
		for(int e=0; e<n; e++){
			char c; cin >> c;
			if(c == '*') m[i][e] = true;
		}
	}
	cout << dfs(0, 0);
	return 0;
}
