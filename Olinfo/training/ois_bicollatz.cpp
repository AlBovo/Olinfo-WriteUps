// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	int a, b, tot = 0; fin >> a >> b;
	map<pair<int, int>, bool>m;
	while(a != 1 || b != 1){
		if(m.count({a, b})){
			fout << -1;
			return 0;
		}
		m[{a, b}] = 1;
		if(a % 2 == 0 && b % 2 == 0){
			a /= 2;
			b /= 2;
		}
		else if(a % 2 && b % 2){
			a *= 3; ++a;
			b *= 3; ++b;
		}
		else{
			if(a % 2){
				a += 3;
			}
			else{
				b += 3;
			}
		}
		tot++;
	}
	fout << tot;
	return 0;
}
