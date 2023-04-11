#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	int t; fin >> t;
	for(int e=0; e<t; e++){
		int n, tot = 0; fin >> n;
		vector<int>v(n);
		for(int &i:v){
			fin >> i;
		}
		bool fatto = true;
		while(fatto){
			fatto = false;
			pair<int,int> mini = {(int)10e8, 0};
			for(int i=0; i<=n; i++){
				if(i == n){
					for(int f=mini.second; f<i; f++){
						if(f == mini.second){
							tot += mini.first;
						}
						v[f]-=mini.first;
						fatto = true;
					}
					mini.second = i+1;
					break;
				}
				if(v[i] <= 0){
					for(int f=mini.second; f<i; f++){
						if(f == mini.second){
							tot += mini.first;
						}
						v[f]-=mini.first;
						fatto = true;
					}
					mini.second = i+1;
				}
				else{
					mini.first = min(mini.first, v[i]);
				}
			}
			for(int &i:v){
				cout << i << " ";
			}
			cout << "\n";
		}
		fout << "Case #" << e+1 << ": " << tot << "\n";
	}
	return 0;
}
