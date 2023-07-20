#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

vector<vector<int>>v;
vector<int>p;

int dfs(int pos){
	if(p[pos] != -1) return p[pos];
	p[pos] = 0;
	for(int &i:v[pos]){
		p[pos] += dfs(i);
	}
	return p[pos] + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	v.resize(n); p.resize(n, -1);
	for(int i=1; i<n; i++){
		int t; cin >> t;
		v[t-1].push_back(i);
	}
	dfs(0);
	for(int &i:p){
		cout << i << " ";
	}
	return 0;
}
