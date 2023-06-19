#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<bool>>ma;
vector<vector<long long>>dp;

long long dfs(int x, int y){
	if(x >= n || y >= m || x < 0 || y < 0) return 0;
	if(ma[x][y]) return 0;
	if(x == n-1 && y == m-1) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = dfs(x+1, y) + dfs(x, y+1);
	return dp[x][y];
}

int main(){
	fin >> n >> m;
	dp.resize(n+1, vector<long long>(m+1, -1));
	ma.resize(n+1, vector<bool>(m+1, false));
	for(int i=0; i<n; i++){
		for(int e=0; e<m; e++){
			char c; fin >> c;
			if(c == '+') ma[i][e] = true;
		}
	}
	fout << dfs(0, 0);
	return 0;
}
