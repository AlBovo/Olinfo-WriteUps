#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long n, q; cin >> n >> q;
	vector<long long>v(n+1, 0);
	for(int i=1; i<=n; i++){
		long long t; cin >> t;
		v[i] = v[i-1] + t;
	}
	for(int i=0; i<q; i++){
		long long a, b; cin >> a >> b;
		cout << v[b]-v[a-1] << "\n";
	}
	return 0;
}
