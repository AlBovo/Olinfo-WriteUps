// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n, m;
vector<int>v;
vector<vector<pair<int, bool>>>dp;
int trova(int pos, int cos){
	if(cos < 0) return -1e9;
	if(pos == n || cos == 0) return 0;
	if(dp[pos][cos].first != -1) return dp[pos][cos].first;
	
	int t = trova(pos+1, cos), t1 = trova(pos+1, cos-v[pos])+v[pos];
	
	dp[pos][cos].first = max(t, t1);
	dp[pos][cos].second = ((t > t1)? 0 : 1);
	
	// cout << "{" << pos << "," << cos << "," << dp[pos][cos] << "}" << "\n";
	
	return dp[pos][cos].first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n); 
	dp.resize(n, vector<pair<int, bool>>(m+1, {-1, 0}));
	for(int &i:v){
		cin >> i;
	}
	
	trova(0, m);
	
	int pos = 0, cos = m;
	while(pos < n){
		if(dp[pos][cos].second){
			cout << v[pos] << "\n";
			cos -= v[pos];
		}
		pos++;
	}
	return 0;
}