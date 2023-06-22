// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	int n, m; fin >> n >> m;
	string s; fin >> s;
	vector<set<char>>v(n);
	for(int i=0; i<m; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			if(s[m - i - 1] >= '0' && s[m - i - 1] <= '9'){
				fout << "impossibile";
				return 0;
			}
			v[s[i]-'0'].insert(s[m - i - 1]);
			// cout << s[i] << ": " << s[m - i - 1] << "\n";
		}
	}
	s = "";
	for(auto &i:v){
		cout << i.size() << " ";
		if(i.size() > 1){
			fout << "impossibile";
			return 0;
		}
		for(char e:i){
			s += e;
		}
	}
	fout << s;
    return 0;
}
