// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
void fastinput(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
}
struct node{
	int colour;
	int tot;
	vector<int> child;
};
struct ret{
	int tot;
	int maxi;
	unordered_map<int, int> *m;
};
int n, c = 0;
vector<node> tree;

ret dfs(int pos){
	unordered_map<int, int> *m = new unordered_map<int, int>();
	(*m)[tree[pos].colour] = 1;
	int maxi = 1, tot = 1;
	for(int &i : tree[pos].child){
		auto t = dfs(i);
		if(t.m->size() > m->size()){ // merge m into t
			maxi = t.maxi;
			tot = t.tot;
			for(auto &i : (*m)){
				(*t.m)[i.first] += i.second;
				if((*t.m)[i.first] > maxi){
					maxi = (*t.m)[i.first];
					tot = 1;
				}
				else if((*t.m)[i.first] == maxi) tot++;
			}
			delete m;
			m = t.m;
		}
		else{ // merge t into m
			for(auto &i : (*t.m)){
				(*m)[i.first] += i.second;
				if((*m)[i.first] > maxi){
					maxi = (*m)[i.first];
					tot = 1;
				}
				else if((*m)[i.first] == maxi) tot++;
			}
			delete t.m;
		}
	}
	tree[pos].tot = tot;
	return {tot, maxi, m};
}
int main(){
	fastinput();
	cin >> n;
	tree.resize(n);
	for(auto &i : tree){
		cin >> i.colour;
		c = max(c, i.colour+1);
	}
	for(int i=1; i<n; i++){
		int par; cin >> par;
		tree[par].child.push_back(i);
	}
	dfs(0);
	/*
	for(auto &i : tree){
		cout << i.tot << "\n";
	}
	*/
	int resp = -1;
	for(auto &i : tree) resp = max(resp, i.tot);
	cout << resp;
	return 0;
}
