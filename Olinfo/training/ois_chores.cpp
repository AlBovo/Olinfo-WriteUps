// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
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
	int n; fin >> n;
	v.resize(n);
	for(int i=0; i<n; i++){
		int a, b; fin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dp.resize(n, {0, 0});
	auto far = trova(0, -1);
	dp.clear(); dp.resize(n, {0, 0});
	fout << trova(far.second, -1).first * 2;
	return 0;
}
