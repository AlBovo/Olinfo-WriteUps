// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
vector<vector<int>>v;
vector<int>t;
int trova(int pos){
	int tot = 1;
	for(int i:v[pos]){
		tot += trova(i);
	}
	t[pos] = tot;
	return tot;
}
int coppie(int N, int C[]){
	int tot = 0, rad; v.resize(N); t.resize(N, 0);
	for(int i=0; i<N; i++){
		if(C[i] == -1){
			rad = i;
		}
		else{
			v[C[i]].push_back(i);
		}
	}
	trova(rad);
	for(int &i:t){
		tot += i-1;
	}
	return tot;
}
#ifndef EVAL
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int C[n];
	for(int i=0; i<n; i++){
		cin >> C[i];
	}
	cout << coppie(n, C);
	return 0;
}
#endif
