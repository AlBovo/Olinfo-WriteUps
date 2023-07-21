// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
unordered_map<string, int>dp;
unordered_set<string>s;
int trova(string t){
	if(t.size() == 0) return 0;
	if(dp.count(t)) return dp[t];
	// cout << t << " ";
	string f; int maxi = 0;
	for(int i=0; i<t.size(); i++){
		for(int e=i+1; e<t.size(); e++){
			f = t;
			if(f[i] < f[e]) f[i] = f[e];
			else continue;
			// cout << f << "\n";
			if(!s.count(f)) continue;
			maxi = max(maxi, trova(f) + 1);
		}
	}
	for(int i=0; i<t.size(); i++){
		f = t.substr(0, i) + t.substr(i+1, t.size()-i+1);
		// cout << f << "\n";
		if(!s.count(f)) continue;
		maxi = max(maxi, trova(f) + 1);
	}
	// cout << maxi << "\n";
	dp[t] = maxi;
	return dp[t];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string t, f;
	for(int i=0; i<n; i++){
		cin >> t;
		s.insert(t);
		if(i == 0) f = t;
	}
	int maxi = 0;
	for(string r : s){
		maxi = max(maxi, trova(r) + 1);
	}
	cout << maxi;
	return 0;
}
