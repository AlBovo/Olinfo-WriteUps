#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long n, last = 0, curr, tot = 0; cin >> n;
	for(int i=0; i<n; i++){
		if(!i){ cin >> last; }
		else{
			cin >> curr;
			if(curr < last){ tot += last - curr; }
			else{ last = curr; }
		}
	}
	cout << tot << "\n";
	return 0;
}