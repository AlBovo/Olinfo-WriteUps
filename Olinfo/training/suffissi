// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	unordered_set<int>s;
	vector<int>v(n), t(n, 0);
	for(int &i:v){
		cin >> i;
	}
	t[n-1] = 1;
	s.insert(v[n-1]);
	for(int i=n-2; i>=0; i--){
		if(!s.count(v[i])){
			t[i] = t[i+1] + 1;
			s.insert(v[i]);
		}
		else{
			t[i] = t[i+1];
		}
	}
	for(int i=0; i<m; i++){
		int r; cin >> r;
		cout << t[r-1] << "\n";
	}
    return 0;
}
