#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
  int t; fin >> t;
	for(int i=0; i<t; i++){
		int k1 = -1, k2 = 1e9, n, tot = 0; fin >> n;
		vector<int>v, z;
		for(int e=0; e<n; e++){
			int val; fin >> val;
			if(val == -1){
				v.push_back(tot - 1);
				k1 = max(k1, tot - 1);
				tot = 0;
			}
			else{
				if(tot == 0 && !v.empty()){
					z.push_back(val);
				}
				tot += val + 1;
			}
		}
		k1 = max(k1, tot - 1);
		v.push_back(tot);
		for(int e=0; e<(int)v.size() - 1; e++){
			if(v[e] + z[e] <= k1){ continue; }
			k2 = min(k2, v[e] + z[e]);
			//cout << "{" << k2 << "," << e << "}\n";
		}
		fout << "Case #" << i+1 << ": " << k1 << " " << ((k2 == 1e9)? k1 : k2) << "\n";
	}
	return 0;	
}
