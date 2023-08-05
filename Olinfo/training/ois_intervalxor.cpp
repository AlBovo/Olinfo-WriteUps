// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		unsigned int q, x; cin >> q;
		
		if(q % 4 == 0) x = q;
		else if(q % 4 == 1){
		    cout << "1 " << q << "\n";
		    continue;
		}
		else if(q % 4 == 2) x = q + 1;
		else if(q % 4 == 3){
		    cout << "0 " << q << "\n";
		    continue;
		}
		
		int l = 32 - __builtin_clz(q); unsigned int t = ((~x) & ((1<<l)-1));
		while(t > q) t -= t & -t;
		cout << x << " " << (x ^ t) << "\n";
	}
	return 0;
}
