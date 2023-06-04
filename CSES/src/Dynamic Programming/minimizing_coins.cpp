#include<bits/stdc++.h>
using namespace std;
vector<int>v, f;

int trova(int q){
	if(q < 0){ return (int)1e9; }
	if(q == 0){ return 0; }
	if(v[q] == 0){
		int mini = 1e9;
		for(int i:f){
			mini = min(mini, trova(q-i) + 1);
		}
		v[q] = mini;
	}
	return v[q];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x; cin >> n >> x;
	v.resize(x+2, 0);
	f.resize(n);
	for(int &i:f){
		cin >> i;
	}
	int r = trova(x);
	cout << ((r > (int)1e6)? -1 : r);
	return 0;
}
