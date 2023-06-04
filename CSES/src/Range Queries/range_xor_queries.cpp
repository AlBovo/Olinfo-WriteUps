#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	vector<int>v(n+1, 0);
	for(int i=1; i<=n; i++){
		int t; cin >> t;
		v[i] = v[i-1] ^ t;
	}
	for(int i=0; i<q; i++){
		int a, b; cin >> a >> b;
		cout << (int)(v[a-1] ^ v[b]) << "\n";
	}
	return 0;
}
