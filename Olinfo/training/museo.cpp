// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
struct Segtree {
    int n, size;
    vector<int> tree;
    int getmax(int pos, int nl, int nr, int ql, int qr) {
        if(nl >= qr || nr <= ql){
            return -1e9;
        }
        if(nl >= ql && nr <= qr){
            return tree[pos];
        }
        return max(
            getmax(pos*2, nl, (nl+nr)/2, ql, qr),
            getmax(pos*2+1, (nl+nr)/2, nr, ql, qr)
        );
    }
    void update(int pos, int x){
        pos += size;
        tree[pos] = x;
        pos /= 2;
        while(pos > 0) {
            tree[pos] = max(tree[pos*2], tree[pos*2+1]);
            pos /= 2;
        }
    }
    Segtree(vector<int> v) {
        n = v.size();
        size = 1 << (int)(ceil(log2((int)v.size())));
        tree.resize(2 * size);
        
        for(int i=0; i<n; i++)
            tree[i+size] = v[i];
        for(int i=size-1; i>0; i--)
            tree[i] = max(tree[i*2], tree[i*2 + 1]);
    }
};
Segtree seg = Segtree({0});
void inizia(int N, vector<int> A) { seg = Segtree(A); }
void aggiorna(int P, int X) {
    seg.update(P, X);
}
int massimo(int L, int R) { return seg.getmax(1, 0, seg.size, L, R+1); }
#ifndef EVAL
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int &x: A)
        cin >> x;
    inizia(N, A);
    for (int i = 0; i < Q; i++) {
        char t;
        cin >> t;
        if (t == 'U') {
            int P, V;
            cin >> P >> V;
            aggiorna(P, V);
        }
        if (t == 'Q') {
            int L, R;
            cin >> L >> R;
            cout << massimo(L, R) << "\n";
        }
    }
}
#endif