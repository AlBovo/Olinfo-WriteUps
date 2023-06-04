#include<bits/stdc++.h>
using namespace std;
vector<long long>v;

long long sum(int p){
	long long s = 0;
	for(; p>0; p-=p&-p){
		s += v[p];
	}
	return s;
}

void update(int p, int d){
	d -= sum(p) - sum(p-1);
	for(; p<(long long)v.size(); p+=p&-p){
		v[p] += d;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	v.resize(n+1, 0);
	for(int i=0; i<n; i++){
		int t; cin >> t;
		update(i+1, t);
	}
	for(int i=0; i<q; i++){
		int k, a, b; cin >> k >> a >> b;
		if(k == 1){
			update(a, b);
		}
		else{
			cout << sum(b) - sum(a-1) << "\n";
		}
	}
	return 0;
}
