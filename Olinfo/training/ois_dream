// Punti: 35.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define MOD (long long)(666013)
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long n, x, t = 0; cin >> n >> x;
	for(long long i=0, c = 0; i<n; i++){
		string s = "";
		if(!i){
			c = pow(10, (x/2)-1);
		}
		else{
			c++;
		}
		long long f = c, q = c;
		for(int e=0; e<x/2; e++){
			q *= 10;
			q += f%10;
			f /= 10;
		}
		// cout << q << "\n";
		t = ((t % MOD) + (q  % MOD)) % MOD; 
	}
	cout << t;
    return 0;
}
