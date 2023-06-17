// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;

int n, f;
vector<int> n1, f1;
vector<vector<int>>um(1001, vector<int>(1001, -1));

int dp(int m, int r){
	if(m >= n || r >= f) return 0;
	if(um[m][r] != -1) return um[m][r];
	int maxi = abs(n1[m] - f1[r]);
	um[m][r] = max({dp(m+1, r), dp(m, r+1), maxi + dp(m+1, r+1)});
	return um[m][r];
}

int main(){
	cin >> n >> f;
	n1.resize(n, 0); f1.resize(f, 0);
	for(int &i:n1){
		cin >> i;
	}
	for(int &i:f1){
		cin >> i;
	}
	cout << dp(0, 0);
	return 0;
}
