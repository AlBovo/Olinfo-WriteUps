// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct node{
    long long values;
    long long valuem;
    bool update;
    long long updateval;
};

class Segtree{
private:
    vector<node>seg;
    int size, n;
    long long get_sum(int node, int nl, int nr, int ql, int qr){
        if(nl >= qr || nr <= ql){
            return 0;
        }
        if(nl >= ql && nr <= qr){
            return seg[node].values;
        }
        propagate(node, nl, nr);
        long long left = get_sum(node * 2, nl, (nl + nr)/2, ql, qr);
        long long right = get_sum(node * 2 + 1, (nl + nr) / 2, nr, ql, qr);
        return left + right;
    }
    long long get_min(int node, int nl, int nr, int ql, int qr){
        if(nl >= qr || nr <= ql){
            return (long long)1e18;
        }
        if(nl >= ql && nr <= qr){
            return seg[node].valuem;
        }
        propagate(node, nl, nr);
        long long left = get_min(node * 2, nl, (nl + nr)/2, ql, qr);
        long long right = get_min(node * 2 + 1, (nl + nr) / 2, nr, ql, qr);
        return min(left, right);
    }
    int lower_bound(int node, int nl, int nr, int ql, int qr, long long x){
        if(nl >= qr || nr <= ql || seg[node].valuem > x){
            return -1;
        }
        if(nl + 1 == nr){
            return nl;
        }
        propagate(node, nl, nr);
        long long left = lower_bound(node * 2, nl, (nl + nr)/2, ql, qr, x);
        if(left != -1) return left;
        long long right = lower_bound(node * 2 + 1, (nl + nr) / 2, nr, ql, qr, x);
        return right;
    }
    void set_range(int node, int nl, int nr, int ql, int qr, long long x){
        if(nl >= qr || nr <= ql){
            return;
        }
        if(nl >= ql && nr <= qr){
            seg[node].values = x * (nr - nl);
            seg[node].valuem = x;
            seg[node].update = true;
            seg[node].updateval = x;
            return;
        }
        if(nl + 1 == nr){
            seg[node].values = x;
            seg[node].valuem = x;
            seg[node].update = false;
            seg[node].updateval = 0;
            return;
        }
        propagate(node, nl, nr);
        set_range(node * 2, nl, (nl+nr)/2, ql, qr, x);
        set_range(node * 2 + 1, (nl + nr)/2, nr, ql, qr, x);
        seg[node].values = seg[node * 2].values + seg[node * 2 +1].values;
        seg[node].valuem = min(seg[node * 2].valuem, seg[node * 2 +1].valuem);
    }
    void add(int node, int nl, int nr, int ql, int qr, long long x){
        if(nl >= qr || nr <= ql){
            return;
        }
        if(nl >= ql && nr <= qr){
            seg[node].values += x * (nr - nl);
            seg[node].valuem += x;
            seg[node].updateval += x;
            return;
        }
        if(nl+1 == nr){
            seg[node].values += x;
            seg[node].valuem += x;
            seg[node].update = false;
            seg[node].updateval = 0;
            return;
        }
        propagate(node, nl, nr);
        add(node * 2, nl, (nl+nr)/2, ql, qr, x);
        add(node * 2 + 1, (nl + nr)/2, nr, ql, qr, x);
        seg[node].values = seg[node * 2].values + seg[node * 2 +1].values;
        seg[node].valuem = min(seg[node * 2].valuem, seg[node * 2 +1].valuem);
    }
    void propagate(int node, int nl, int nr){
        if(seg[node].update){
            seg[node*2].valuem = seg[node].updateval;
            seg[node*2].values = seg[node].updateval * ((nr+nl)/2 - nl );
            seg[node*2].update = true;
            seg[node*2].updateval = seg[node].updateval;
            seg[node*2 + 1].valuem = seg[node].updateval;
            seg[node*2 + 1].values = seg[node].updateval * (nr - (nr+nl)/2);
            seg[node*2 + 1].update = true;
            seg[node*2 + 1].updateval = seg[node].updateval;
        }
        else{
            seg[node*2].valuem += seg[node].updateval;
            seg[node*2].values += seg[node].updateval * ((nr+nl)/2 - nl );
            seg[node*2].updateval += seg[node].updateval;
            seg[node*2 + 1].valuem += seg[node].updateval;
            seg[node*2 + 1].values += seg[node].updateval * (nr - (nr+nl)/2);
            seg[node*2 + 1].updateval += seg[node].updateval;
        }
        seg[node].update = false;
        seg[node].updateval = 0;
    }
public:
    Segtree(int sizep, const vector<long long>&a){
        n = sizep;
        size = 1 << (int)(ceil(log2(sizep)));
        node n;
        n.values = 0;
        n.valuem = (long long)1e18;
        n.updateval = 0;
        n.update = false;
        seg.resize(2 * size, n);
        for(int i=0; i<sizep; i++){
            seg[i+size].values = a[i];
            seg[i+size].valuem = a[i];
        }
        for(int i=size-1; i>0; i--){
            seg[i].values = seg[i*2].values + seg[i*2+1].values;
            seg[i].valuem = min(seg[i*2].valuem, seg[i*2+1].valuem);
        }
    }
    long long get_sum(int ql, int qr){
        return get_sum(1, 0, size, ql, qr);
    }
    long long get_min(int ql, int qr){
        return get_min(1, 0, size, ql, qr);
    }
    int lower_bound(int ql, int qr, long long x){
        long long l = lower_bound(1, 0, size, ql, qr, x);
        return l;
    }
    void set_range(int ql, int qr, long long x){
        set_range(1, 0, size, ql, qr, x);
    }
    void add(int ql, int qr, long long x){
        add(1, 0, size, ql, qr, x);
    }
};
Segtree seg(1, vector<long long>(1));

void init(vector<long long> a){
    seg = Segtree(a.size(), a);
}
long long get_sum(int l, int r){
    return seg.get_sum(l, r);
}
long long get_min(int l, int r){
    return seg.get_min(l, r);
}
int lower_bound(int l, int r, long long x){
    return seg.lower_bound(l, r, x);
}
void set_range(int l, int r, long long x){
    seg.set_range(l, r, x);
}
void add(int l, int r, long long x){
    seg.add(l, r, x);
}

#ifndef EVAL
int main(){
    int n, q; fin >> n >> q;
    vector<long long>v(n);
    for(long long &i:v){
        fin >> i;
    }
    init(v);
    for(int i=0; i<q; i++){
        int m; fin >> m;
        int l, r;
        long long x;
        switch (m){
        case 1:
            fin >> l >> r;
            cout << get_sum(l, r) << "\n";
            break;
        case 2:
            fin >> l >> r >> x;
            add(l, r, x);
            break;
        case 3:
            fin >> l >> r >> x;
            set_range(l, r, x);
            break;
        case 4:
            fin >> l >> r;
            cout << get_min(l, r) << "\n";
            break;
        case 5:
            fin >> l >> r >> x;
            cout << lower_bound(l, r, x) << "\n";
            break;
        }
    }
    return 0;
}
#endif