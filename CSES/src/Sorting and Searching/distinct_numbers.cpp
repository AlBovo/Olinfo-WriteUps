#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, tot = 1; cin >> n;
	vector<int>v(n);
	for(int &i:v){
		cin >> i;
	}
	sort(v.begin(), v.end());
	for(int i=1; i<n; i++){
		if(v[i] != v[i-1]){ tot++; }
	}
	cout << tot;
	return 0;
}
