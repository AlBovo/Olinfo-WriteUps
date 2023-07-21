// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, tot = 0; fin >> n;
	vector<int>v(n);
	vector<vector<int>>f(n);
	for(int i=0; i<n; i++){
		fin >> v[i];
		int b; fin >> b;
		if(b == -1) continue;
		f[b].push_back(i);
	}
	/*
	for(int i=0; i<n; i++){
		cout << i << ": ";
		for(int e:f[i]){
			cout << e << " ";
		}
		cout << "\n";
	}
	*/
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		for(int i:f[pos]){
			tot += v[pos] < v[i];
			v[i] = min(v[pos], v[i]);
			q.push(i);
		}
	}
	fout << tot;
	return 0;
}
