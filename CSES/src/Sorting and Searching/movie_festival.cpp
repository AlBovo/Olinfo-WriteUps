#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
bool sorta(pair<int, int> &a, pair<int, int> &b){
	return a.second < b.second;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<pair<int, int>>v(n);
	for(int i=0; i<n; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), sorta);
	/*
	for(auto i:v){
		cout << i.first << " " << i.second << "\n";
	}
	*/
	int pos = v[0].second, tot = 1, i = 0;
	while(i < n){
		for(; i<n; i++){
			if(v[i].first >= pos){
				pos = v[i].second;
				++tot;
			}
		}
	}
	cout << tot;
	return 0;
}
