// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<int>>v;
vector<int>tot;
vector<float>po;
float trova(int pos){
	if(po[pos] != 0) return po[pos]; 
	for(int &i:v[pos]){
		po[pos] += trova(i) / (float)(tot[i]);
	}
	return po[pos];
}
int main(){
	int n, m, p; fin >> n >> m >> p;
	v.resize(n); po.resize(n, 0); tot.resize(n, 0);
	for(int i=0; i<m; i++){
		int a, b; fin >> a >> b;
		v[b].push_back(a);
		tot[a]++;
	}
	po[0] = 1;
	float maxi = -1; int poo = 0;
	for(int i=n-p; i<n; i++){
		float t = trova(i);
		// cout << i << " " << t << "\n";
		if(t > maxi){
			maxi = t;
			poo = i;
		}
	}
	fout << poo;
	return 0;
}
