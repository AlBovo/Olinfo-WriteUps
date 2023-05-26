#include<bits/stdc++.h>
using namespace std;

class segtree{
private:
	vector<long long>v;
	long long size;
	long long getmin(int node, int nl, int nr, int ql, int qr){
		if(nl >= ql && nr <= qr){
			return v[node];
		}
		if(nr <= ql || nl >= qr){
			return (long long)1e18;
		}
		long long left = getmin(node*2, nl, (nl+nr)/2, ql, qr);
		long long right = getmin(node*2+1, (nl+nr)/2, nr, ql, qr);
		return min(left, right);
	}
public:
	segtree(int n){
		size = 1 << (int)(ceil(log2(n)));
		v.resize(size*2, (int)1e18);
		for(int i=size; i<size+n; i++){
			cin >> v[i];
		}
		for(int i=size-1; i>0; i--){
			v[i] = min(v[i*2], v[i*2+1]);
		}
	}
	long long getmin(int a, int b){
		return getmin(1, 0, size, a, b);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	segtree seg(n);
	for(int i=0; i<q; i++){
		int a, b; cin >> a >> b;
		cout << seg.getmin(a-1, b) << "\n";
	}
	return 0;
}
