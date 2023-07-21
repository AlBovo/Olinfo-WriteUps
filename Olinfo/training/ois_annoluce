// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	int n, m; fin >> n;
	vector<long double>v;
	for(int i=0; i<n; i++){
		long long a, b, c; fin >> a >> b >> c;
		v.push_back(sqrtl(powl(a, 2) + powl(b, 2) + powl(c, 2)));
	}
	sort(v.begin(), v.end());
	fin >> m;
	for(int i=0; i<m; i++){
		int q; fin >> q;
		fout << upper_bound(v.begin(), v.end(), (long double)(q)) - v.begin() << "\n";
	}
	return 0;
}
