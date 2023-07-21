// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int n;
vector<int>v;
vector<vector<vector<long long>>> dp;
long long trova(int pos, bool r, bool p){
	if(pos >= n || (pos == n-1 && p)) return 0;
	if(dp[pos][r][p] != -1) return dp[pos][r][p];
	if(r){
		dp[pos][r][p] = trova(pos + 1, false, p);
	} else {
		dp[pos][r][p] = max(trova(pos + 1, false, p), trova(pos + 1, true, ((pos == 0)? true : p)) + v[pos]);
	}
	
	return dp[pos][r][p];
}
int main(){
	fin >> n;
	v.resize(n);
	dp.resize(n, vector<vector<long long>>(2, vector<long long>(2, -1)));
	for(int &i:v){
		fin >> i;
	}
	fout << trova(0, false, false);
	return 0;
}
