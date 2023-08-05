// Punti: 50.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define MAXN 100000
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	int n, m, tot = 0; fin >> n >> m;
	vector<int>v(n);
	for(int &i:v){
		fin >> i;
	}
	for(int i=0; i<m; i++){
		int last = -2;
		bool fatto = false;
		for(int e=0; e<n; e++){
			if(e == last+1){
				continue;
			}
			if(!e){
				if(v[e] > v[e+1]){
					v[e] = 0;
					last = e;
					tot++;
					fatto = true;
				}
			}
			else if(e == n-1){
				if(v[e] > v[e-1]){
					v[e] = 0;
					last = e;
					fatto = true;
					tot++;
				}
			}
			else if(v[e] > v[e-1] && v[e] > v[e+1]){
				v[e] = 0;
				last = e;
				fatto = true;
				tot++;
			}
		}
		if(!fatto){
			break;
		}
	}
	cout << tot;
	return 0;
}
