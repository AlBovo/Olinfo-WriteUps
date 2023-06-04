#include<bits/stdc++.h>
using namespace std;
unordered_map<int, long long>m;

long long trova(int q){
	if(q < 0){ return 0; }
	if(q == 0){ return 1; }
	if(!m.count(q)){
		long long sum = 0;
		for(int i=1; i<=6; i++){
			sum += trova(q-i) % ((int)(1e9)+7);
		}
		m[q] = sum % ((int)(1e9)+7);
	}
	return m[q];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	cout << trova(n) % ((int)(1e9)+7);
	return 0;
}
