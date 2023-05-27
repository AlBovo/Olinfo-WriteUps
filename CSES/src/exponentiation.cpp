#include<bits/stdc++.h>
#define MODULO 1000000007
using namespace std;

long long fast_exp(int b, int e){
	if(e == 0){ return 1; }
	if(e == 1){ return b; }
	long long f = fast_exp(b, e/2);
	if(e % 2){
		return (f % MODULO * f % MODULO * b % MODULO) % MODULO;
	}
	return (f % MODULO * f % MODULO) % MODULO;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		cout << fast_exp(a, b) << "\n";
	}
	return 0;
}
