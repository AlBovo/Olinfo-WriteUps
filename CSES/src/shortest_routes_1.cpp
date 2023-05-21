#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>>v(n);
	vector<long long>p(n, (long long)1e18);
	vector<bool>vis(n, false);
	p[0] = 0;
	for(int i=0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		v[a-1].push_back({b-1, c});
	}
	priority_queue<pair<long long, int>>q;
	q.push({0, 0});
	while(!q.empty()){
		int pos = q.top().second;
		q.pop();
		if(vis[pos]){ continue; }
		vis[pos] = true;
		for(auto i:v[pos]){
			if(p[pos] + i.second < p[i.first]){
				p[i.first] = p[pos] + i.second;
				q.push({p[i.first] * -1, i.first});
			}
		}
	}
	for(auto i:p){
		cout << i << " ";
	}
	return 0;	
}
