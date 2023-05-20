#include<bits/stdc++.h>
using namespace std;

long long fast_exp(int b, int e, int m){
	if(e == 0){ return 1; }
	if(e == 1){ return b % m; }
	long long f = fast_exp(b, e/2, m) % m;
	if(e % 2 == 0){
		return (f * f) % m;
	}
	return (f * f * (b % m)) % m;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	cout << fast_exp(2, n, (int)(1e9)+7);
	return 0;	
}
