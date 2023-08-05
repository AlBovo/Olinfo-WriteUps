// Punti: 34.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int>cl, idv;
void inizia(int N, int ids[]){
	cl.resize(N); idv.resize(N);
	for(int i=0; i<N; i++){
		cl[i] = ids[i];
		idv[ids[i]] = i;
	}
}
void supera(int id){
	// cerr << id << " S\n";
	idv[id]--;
	int idsuperato = cl[idv[id]];
	cl[idv[id]] = id;
	idv[idsuperato]++;
	cl[idv[idsuperato]] = idsuperato;
}
void squalifica(int id){
	//cerr << id << " X " << idv[id] << "\n";
	for(int i=idv[id]+1; i<(int)cl.size(); i++){
		idv[cl[i]]--;
	}
	cl.erase(cl.begin()+idv[id]);
}
int partecipante(int pos){
	return cl[pos-1];
}
#ifndef EVAL
int main(){
	int n, m; fin >> n >> m;
	int v[n];
	for(int &i:v){
		fin >> i;
	}
	inizia(n, v);
	for(int i=0; i<m; i++){
		char q; int x; fin >> q >> x;
		if(q == 's'){
			supera(x);
		} else if(q == 'x'){
			squalifica(x);
		} else {
			fout << partecipante(x) << " ";
		}
	}
	return 0;
}
#endif
