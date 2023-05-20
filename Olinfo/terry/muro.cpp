#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	int t; fin >> t;
	for(int i=0; i<t; i++){
		int tot = 0, n, q; fin >> n >> q;
		for(int e=0; e<q; e++){
			int val; fin >> val;
			if(tot + val > n){
				tot = n - val + 1;
			}
			else{
				tot++;
			}
		}
		fout << "Case #" << i+1 << ": " << tot << "\n";
	}
	return 0;	
}
