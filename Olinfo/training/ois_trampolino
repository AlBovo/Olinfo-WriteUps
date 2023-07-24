// Punti: 70.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
/*
int trova(int pos){
	if(pos > n) return 1e9;
	else if(pos == n) return 0;
	if(dp[pos] != -1) return dp[pos];
	if(n - pos <= v[pos]) return 1;
	
	int mini = 1e9;
	for(int i=1; i<=v[pos]; i++){
		mini = min(mini, trova(pos + i) + 1);
	}
	dp[pos] = mini;
	return mini;
}
*/
int main(){
	int n; fin >> n;
	vector<int>v(n), dp(n, -1);
	for(int &i:v){
		fin >> i;
	}
	function<int(int)> trova = [&trova, &dp, &v, &n](int pos){
		if(pos > n) return (int)1e9;
		else if(pos == n) return 0;
		if(dp[pos] != -1) return dp[pos];
		if(n - pos <= v[pos]) return 1;
		
		int mini = 1e9;
		for(int i=1; i<=v[pos]; i++){
			mini = min(mini, trova(pos + i) + 1);
		}
		dp[pos] = mini;
		return mini;	
	};
	
	fout << trova(0);
	return 0;
}
