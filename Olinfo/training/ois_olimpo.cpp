// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	int n, maxi = 0; fin >> n;
	vector<vector<pair<int, int>>>v(n); // v[persona][0..size]{figlio, distanza}
	for(int i=1; i<n; i++){
		char c; int p, d; fin >> c >> p;
		
		if(c == 'P') d = 1;
		else if(c == 'N') d = 2;
		else d = 3;
		
		v[p].push_back({i, d});
	}
	queue<int>q; q.push(0);
	vector<int>p(n, 0);
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		for(auto i:v[pos]){
			p[i.first] = p[pos] + i.second;
			q.push(i.first);
			maxi = max(maxi, p[i.first]);
		}
	}
	fout << maxi;
	return 0;
}
