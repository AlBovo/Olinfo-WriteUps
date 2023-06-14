#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;

struct node{
	long long p;
	long long l;
	bool lz;
	bool prop;
};

class Segtree{
private:
	int n, sizen;
	vector<node>seg;
	void propagate(int node, int nl, int nr){
		if(!seg[node].prop) return;
		if(seg[node].lz){
			seg[node*2].p += seg[node].l * ((nr+nl)/2 - nl);
			seg[node*2].l += seg[node].l;
			seg[node*2].prop = true;
			seg[node*2 + 1].p += seg[node].l * (nr - (nr+nl)/2);
			seg[node*2 + 1].l += seg[node].l;
			seg[node*2 + 1].prop = true;
		}
		else{
			seg[node*2].p = seg[node].l * ((nr+nl)/2 - nl);
			seg[node*2].l = seg[node].l;
			seg[node*2].lz = false;
			seg[node*2].prop = true;
			seg[node*2 + 1].p = seg[node].l * (nr - (nr+nl)/2);
			seg[node*2 + 1].l = seg[node].l;
			seg[node*2 + 1].lz = false;
			seg[node*2 + 1].prop = true;
		}
        seg[node].l = 0;
		seg[node].lz = true;
		seg[node].prop = false;
	}
	void update(int node, int nl, int nr, int ql, int qr, int x){
		if(nl >= qr || nr <= ql){
			return;
		}
		if(nl >= ql && nr <= qr){
			seg[node].p += x * (long long)(nr - nl);
			seg[node].l += x;
			seg[node].prop = true;
			return;
		}
		propagate(node, nl, nr);
		update(node * 2, nl, (nr+nl)/2, ql, qr, x);
		update(node * 2 + 1, (nl+nr)/2, nr, ql, qr, x);
		seg[node].p = seg[node*2].p + seg[node*2+1].p;
	}
	void set(int node, int nl, int nr, int ql, int qr, int x){
		if(nl >= qr || nr <= ql){
			return;
		}
		if(nl >= ql && nr <= qr){
			seg[node].p = x * (long long)(nr - nl);
			seg[node].l = x;
			seg[node].lz = false;
			seg[node].prop = true;
			return;
		}
		propagate(node, nl, nr);
		set(node * 2, nl, (nr+nl)/2, ql, qr, x);
		set(node * 2 + 1, (nl+nr)/2, nr, ql, qr, x);
		seg[node].p = seg[node*2].p + seg[node*2+1].p;
	}
	long long get(int node, int nl, int nr, int ql, int qr){
		if(nl >= qr || nr <= ql){
			return 0;
		}
		if(nl >= ql && nr <= qr){
			return seg[node].p;
		}
		propagate(node, nl, nr);
		long long left = get(node * 2, nl, (nl+nr)/2, ql, qr);
		long long right = get(node * 2 + 1, (nl+nr)/2, nr, ql, qr);
		return left + right;
	}
public:
	Segtree(int sizep){
		n = sizep;
		sizen = 1 << (int)(ceil(log2(n)));
		seg.resize(sizen*2, node{0, 0, true});
		for(int i=sizen; i<sizen+n; i++){
			cin >> seg[i].p;
		}
		for(int i=sizen-1; i>0; i--){
			seg[i].p = seg[i*2].p + seg[i*2+1].p;
		}
	}
	void update(int ql, int qr, int x){
		update(1, 0, sizen, ql, qr, x);
	}
	void set(int ql, int qr, int x){
		set(1, 0, sizen, ql, qr, x);
	}
	long long get(int ql, int qr){
		return get(1, 0, sizen, ql, qr);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int q, a, b, x;
	Segtree seg(n);
	for(int i=0; i<m; i++){
		cin >> q;
		if(q == 1){
			cin >> a >> b >> x;
			seg.update(a-1, b, x);
		}
		else if(q == 2){
			cin >> a >> b >> x;
			seg.set(a-1, b, x);
		}
		else{
			cin >> a >> b;
			cout << seg.get(a-1, b) << "\n";
		}
	}
	return 0;
}
