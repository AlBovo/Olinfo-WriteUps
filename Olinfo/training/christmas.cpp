// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int n, m, maxi = -1;
vector<int>v;
vector<vector<int>>dpv;
int dp(int p, int i){
	if(p >= m) return 0;
	if(i >= n){
		maxi = max(maxi, p);
		return 1e9;
	}
	if(dpv[i][p] != -1) return dpv[i][p];
	dpv[i][p] = min(dp(p+v[i], i+1)+v[i], dp(p, i+1));
	return dpv[i][p];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n);
	dpv.resize(n, vector<int>(m, -1));
	for(int &i:v){
		cin >> i;
	}
	int boh = dp(0, 0);
	cout << ((boh == (int)1e9)? maxi : boh);
	return 0;
}
