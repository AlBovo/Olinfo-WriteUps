// Punti: 65.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
vector<pair<int, int>>v;
vector<vector<int>>dp;
int n, x;
int trova(int p, int c){
	if(p == n) return 0;
	if(c < 0) return -2;
	while(dp.size() <= p){
		dp.push_back(vector<int>());
	}
	while(dp[p].size() <= c){
		dp[p].push_back(-1);
	}
	if(dp[p][c] != -1) return dp[p][c];
	dp[p][c] = max(trova(p+1, c), ((c >= v[p].second)? trova(p+1, c-v[p].second) + v[p].first : (int)-1e9));
	#ifndef EVAL
	cout << p << ", " << c << ", " << dp[p][c] << "\n";
	#endif
	return dp[p][c];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x;
	// dp.resize(n, vector<int>(x+1, -1));
	v.resize(n);
	for(auto &i:v){
		cin >> i.first >> i.second;
	}
	cout << trova(0, x);
	return 0;
}