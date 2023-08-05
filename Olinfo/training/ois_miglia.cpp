// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<pair<int, int>>>gr;
vector<int>v;
int k, n, m;
int dp(int pos){
	if(v[pos] != -1e9){
		return v[pos];
	}
	for(auto &i:gr[pos]){
		v[pos] = max(v[pos], dp(i.first) + i.second);
	}
	return v[pos];
}
int main(){
	fin >> k >> n >> m;
	gr.resize(n * (k + 1));
	v.resize(n * (k + 1), -1e9);
	for(int i=0; i<m; i++){
		int x, y, z; fin >> x >> y >> z;
		for(int e=0; e<k; e++){
			gr[x*(k+1) + e].push_back({y*(k+1) + e + 1, z});
		}
	}
	v[k] = 0;
	fout << dp(0);
	/*
	for(int i=0; i<n*(k + 1); i++){
		cout << v[i] << " " << i/(k + 1) << " " << i%(k + 1)  << "\n";
	}
	*/
	return 0;
}
