#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<vector<int>>v(100);
map<pair<int, int>, int> m;
int n, k;

int trova(int pos, int lv){
	if(lv == n-1) return v[lv][pos];
	if(!m.count({lv, pos})){
		m[{lv, pos}] = v[lv][pos] + max(trova(pos, lv+1), trova(pos+1, lv+1));
	}	
	return m[{lv, pos}];
}

int main(){
	fin >> n;
	for(int i=0; i<n; i++){
		for(int e=0; e<=i; e++){
			fin >> k;
			v[i].push_back(k); 
		}
	}
	fout << trova(0, 0);
	return 0;
}