#include<bits/stdc++.h>
#pragma GCC optmize("O2")
using namespace std;

struct node{
	long long p;
	long long l;
};

class Segtree{
private:
	int n, sizen;
	vector<node>seg;
	void propagate(int node, int nl, int nr){
		seg[node*2].p += seg[node].l * ((nr+nl)/2 - nl);
		seg[node*2].l += seg[node].l;
		seg[node*2 + 1].p += seg[node].l * (nr - (nr+nl)/2);
		seg[node*2 + 1].l += seg[node].l;

        seg[node].l = 0;
	}
	void update(int node, int nl, int nr, int ql, int qr, long long x){
		if(nl >= ql && nr <= qr){
			seg[node].l += x;
			seg[node].p += x * (nr - nl);
			return;
		}
		if(nr <= ql || nl >= qr){
			return;
		}
		if(nl + 1 == nr){
			seg[node].p += x;
			seg[node].l = 0;
			return;
		}
		propagate(node, nl, nr);
		update(node * 2, nl, (nl + nr)/2, ql, qr, x);
		update(node * 2 + 1, (nl + nr)/2, nr, ql, qr, x);
		seg[node].p = seg[node*2].p + seg[node*2+1].p;
	}
	long long get_value(int node, int nl, int nr, int ql, int qr){
		if(nl == ql && nr == qr){
			//cout << seg[node].l << " " << seg[node].p << "\n";
			return seg[node].p;
		}
		if(nr <= ql || nl >= qr){
			return 0;
		}
		propagate(node, nl, nr);
		long long left = get_value(node * 2, nl, (nl+nr)/2, ql, qr);
		long long right = get_value(node * 2+1, (nl+nr)/2, nr, ql, qr);
		return left + right;
	}
public:
	Segtree(int sizep){
		n = sizep;
		sizen = 1 << (int)(ceil(log2(n)));
		seg.resize(sizen*2, node{0, 0});
		for(int i=sizen; i<sizen+n; i++){
			cin >> seg[i].p;
		}
		for(int i=sizen-1; i>0; --i){
			seg[i].p = seg[i*2].p + seg[i*2+1].p;
		}
		/*
		for(auto i:seg){
			cout << i.p << " ";
		}
		*/
	}
	void update(int a, int b, int x){
		update(1, 0, sizen, a-1, b, x);
	}
	long long get_value(int pos){
		return get_value(1, 0, sizen, pos-1, pos);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	Segtree seg(n);
	int q, a, b, x;
	for(int i=0; i<m; i++){
		cin >> q;
		if(q == 1){
			cin >> a >> b >> x;
			seg.update(a, b, x);
		}
		else{
			cin >> a;
			cout << seg.get_value(a) << "\n";
		}
	}
	return 0;
}
