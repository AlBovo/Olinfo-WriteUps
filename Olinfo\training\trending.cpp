// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	int n, m; fin >> n >> m;
	vector<string>v;
	pair<string, int>best = {"", -1};
	map<string, int>ma;
	for(int i=0; i<m; i++){
		string t; fin >> t;
		v.push_back(t);
		ma[t]++;
		if(best.second < ma[t]){
			best.first = t;
			best.second = ma[t];
		}
		else if(best.second <= ma[t] && best.first > t){
			best.first = t;
			best.second = ma[t];
		}
	}
	cout << best.first << "\n";
	for(int i=m; i<n; i++){
		string t; fin >> t;
		v.push_back(t);
		ma[t]++;
		ma[v[i-m]]--;
		if(v[i-m] == best.first){
			best = {"zzzzz", -1};
			for(auto e:ma){
				if(e.second > best.second){
					best.first = e.first;
					best.second = e.second;
				}
				else if(e.second >= best.second && e.first < best.first){
					best.first = e.first;
					best.second = e.second;
				}
			}
		}
		if(best.second < ma[t]){
			best.first = t;
			best.second = ma[t];
		}
		else if(best.second <= ma[t] && best.first > t){
			best.first = t;
			best.second = ma[t];
		}
		cout << best.first << "\n";
	}
	return 0;
}
