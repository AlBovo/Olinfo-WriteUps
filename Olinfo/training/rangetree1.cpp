// Punti: 100.0
#include<vector>
#include<math.h>
#include<fstream>
#include<iostream>
#pragma GCC optmize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct node{
    int value;
    bool update;
};

class Segtree{
private:
    vector<node>seg;
    int size, n;
    int get_sum(int node, int nl, int nr, int ql, int qr){
        if(nl >= qr || nr <= ql){
            return 0;
        }
        if(nl >= ql && nr <= qr){
            return seg[node].value;
        }
        propagate(node, nl, nr);
        int left = get_sum(node * 2, nl, (nl + nr)/2, ql, qr);
        int right = get_sum(node * 2 + 1, (nl + nr)/2, nr, ql, qr);
        return left + right;
    }
    void update(int node, int nl, int nr, int ql, int qr){
        if(nl >= qr || nr <= ql){
            return;
        }
        if(nl >= ql && nr <= qr){
            seg[node].value = (nr-nl)-seg[node].value;
            seg[node].update = !seg[node].update;
            return;
        }
        propagate(node, nl, nr);
        update(node * 2, nl, (nr + nl)/2, ql, qr);
        update(node * 2 + 1, (nl + nr)/2, nr, ql, qr);
        seg[node].value = seg[node * 2].value + seg[node * 2 + 1].value;
    }
    void propagate(int node, int nl, int nr){
        if(!seg[node].update){ return; }
        seg[node * 2].value = (nr-nl)/2-seg[node * 2].value;
        seg[node * 2].update = !seg[node * 2].update;
        seg[node * 2 + 1].value = (nr-nl)/2-seg[node * 2 + 1].value;
        seg[node * 2 + 1].update = !seg[node * 2 + 1].update;

        seg[node].update = false;
    }
public:
    Segtree(int sizep){
        n = sizep;
        size = 1 << (int)(ceil(log2(sizep)));
        node n;
        n.value = 0;
        n.update = false;
        seg.resize(2 * size, n);
    }
    int get_sum(int l, int r){
        return get_sum(1, 0, size, l, r);
    }
    void update(int l, int r){
        update(1, 0, size, l, r);
    }
};

int main(){
    int n, m; fin >> n >> m;
    Segtree seg(n);
    for(int i=0; i<m; i++){
        int q, a, b; fin >> q >> a >> b;
        if(q == 0){
            seg.update(a, b+1);
        }
        else{
            fout << seg.get_sum(a, b+1) << "\n";
        }
    }
    return 0;
}