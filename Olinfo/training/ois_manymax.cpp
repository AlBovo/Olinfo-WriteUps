// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
#define int long long
static constexpr int MOD = 1e9+7;

struct node{
	int cnt;
	int prod;
	node* l;
	node* r;
};

node storage[10000000];
int alloc_i = 0;
node* alloc() { return storage+(alloc_i++); }
node* alloc(const node& x) { storage[alloc_i] = x; return storage+(alloc_i++); }
node* alloc(node&& x) { storage[alloc_i] = x; return storage+(alloc_i++); }

int N;
vector<node*> versions;

node* merge(node* a, node* b){
	node* x = alloc();
	x->prod = (a->prod * b->prod) % MOD;
    x->cnt = (a->cnt + b->cnt);
	x->l = a;
	x->r = b;
	return x;
}

node* build(int l, int r){
	if (l == r-1) return alloc(node{0,1});
	int m = (l+r)/2;
	return merge(build(l,m), build(m,r));
}

node* add(int a, node* x, int l, int r){
	if (a < l || a >= r) return x;
	if (r - l == 1){
		node* res = alloc(*x);
		res->cnt += 1;
		res->prod = (res->prod * (long long) a) % MOD;
		return res;
	}
	int m = (l+r)/2;
	return merge(add(a,x->l,l,m), add(a,x->r,m,r));
}

static constexpr int MAXV = 200002;
vector<int> inverse(MAXV);

int fastexp(int x, int y){
    if (y == 0)
        return 1;
    int tmp = fastexp(x, y/2);
    tmp = (tmp * (long long) tmp) % MOD;
    if (y&1)
        tmp = (tmp * (long long) x) % MOD;
    return tmp;
}

int query(node* v1, node* v2, int k, int l, int r){
    if (r - l == 1){
        return fastexp(l, min(v2->cnt - v1->cnt, k));
    }
    if (v2->cnt - v1->cnt <= k)
        return (v2->prod * (long long) fastexp(v1->prod, MOD - 2)) % MOD;
    int m = (l + r) / 2;

    int tmp = query(v1->r, v2->r, k, m, r);
    if (v2->r->cnt - v1->r->cnt < k)
        tmp = (tmp * (long long) query(v1->l, v2->l, k - (v2->r->cnt - v1->r->cnt), l, m)) % MOD;
    return tmp;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, Q;
    cin >> N >> Q;

    versions.push_back(build(0, MAXV));
    for (int i = 0; i < N; ++i){
        int x;
        cin >> x;
        versions.push_back(add(x, versions.back(), 0, MAXV));
        //cout << versions.back()->prod << " " << versions.back()->cnt << endl;
    }

    while (Q--){
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(versions[l], versions[r + 1], k, 0, MAXV) << '\n';
    }
}