// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	int n, m; fin >> n >> m;
	vector<int>v(n);
	for(int &i:v){
		fin >> i;
	}
	int tot = 0;
	for(int i=0; i<m; i++){
		int a, b; fin >> a >> b;
		tot += v[a] && v[b];
	}
	fout << tot;
	return 0;
}
