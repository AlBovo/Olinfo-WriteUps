// Punti: 52.63
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
bool sortafun(pair<string, int>&a, pair<string, int>&b){
	return a < b;
}
int main(){
	string s; fin >> s;
	vector<pair<string, int>>v;
	for(int i=0; i<(int)s.size(); i++){
		v.push_back({s.substr(i, s.size()-i), i});
	}
	sort(v.begin(), v.end(), sortafun);
	/*
	for(auto i:v){
		cout << "{" << i.first << "," << i.second << "}" << "\n";
	}
	*/
	for(auto &i:v){
		fout << i.second << " ";
	}
    return 0;
}
