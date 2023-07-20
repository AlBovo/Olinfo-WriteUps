#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
 
vector<vector<int>>v;
vector<pair<int, int>>dp;
 
pair<int, int> trova(int pos, int pre){
	if(dp[pos].first != 0) return dp[pos];
	int maxi = 0, far = pos;	
	for(int &i:v[pos]){
		if(i == pre) continue;
		auto r = trova(i, pos);
		if(r.first + 1 > maxi){
			maxi = r.first + 1;
			far = r.second;
		}
	}
	dp[pos] = {maxi, far};
	return {maxi, far};
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	++n;
	v.resize(n);
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dp.resize(n, {0, 0});
	auto far = trova(1, -1);
	dp.clear(); dp.resize(n, {0, 0});
	cout << trova(far.second, -1).first;
	return 0;
}
