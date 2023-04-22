// Punti: 100.0
#include<vector>
#include<utility>
#include<math.h>
#pragma GCC optimize("Ofast")

class Segtree{
private:
    std::vector<int>seg;
    int n, size;
    int find(int node, int nl, int nr, int ql, int qr, int x){
        int right = 0, left = 0;
        if(nl >= qr || nr <= ql || seg[node] <= x){
            return -1;
        }
        if(nl + 1 == nr){
            return nl;
        }
        if(ql == 0){
            right = find(node * 2 + 1, (nl+nr)/2, nr, ql, qr, x);
            if(right != -1) return right;
            left = find(node * 2, nl, (nl+nr)/2, ql, qr, x);
            return left;
        }
        else{
            left = find(node * 2, nl, (nl+nr)/2, ql, qr, x);
            if(left != -1) return left;
            right = find(node * 2 + 1, (nl+nr)/2, nr, ql, qr, x);
            return right;
        }
    }
    void update(int node, int x){
        node += size;
        seg[node] = x;
        node /= 2;
        while(node > 0){
            seg[node] = std::max(seg[node * 2], seg[node * 2 + 1]);
            node /= 2;
        }
    }
public:
    Segtree (const std::vector<int>&a){
        n = a.size();
        size = 1 << (int)(std::ceil(std::log2(a.size())));
        seg.resize(2*size);
        for(int i=0; i<n; i++){
            seg[i+size] = a[i];
        }
        for(int i=size-1; i>0; i--){
            seg[i] = std::max(seg[i*2], seg[i*2+1]);
        }
    }
    void cambia(int x, int h){
        update(x, h);
    }
    std::pair<int, int> chiedi(int x){
        std::pair<int, int> e = {0, 0};
        auto i = find(1, 0, size, 0, x, seg[x+size]);
        auto p = find(1, 0, size, x+1, size, seg[x+size]);
        (i == -1)? e.first = 0 : e.first = i;
        (p == -1)? e.second = n-1 : e.second = p;
        return e;
    }
};

Segtree seg(std::vector<int>(1));

void inizializza(int N, std::vector<int> H){
    seg = Segtree(H);
}

void cambia(int x, int h){
    seg.cambia(x, h);
}

std::pair<int, int> chiedi(int x){
    return seg.chiedi(x);
}