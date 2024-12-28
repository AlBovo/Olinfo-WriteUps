// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
struct DSU {
    int total;
    vector<int> p, size;
    DSU(int n) : total(n), p(n, 0), size(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    
    int find_set(int v) {
        if (v == p[v])
            return v;
        return p[v] = find_set(p[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            p[b] = a;
            size[a] += size[b];
            total--;
        }
    }
};
DSU dsu = 0;
void inizia(int N) { dsu = DSU(N); }
int collega(int X, int Y) {
    dsu.union_sets(X, Y);
    return dsu.total;
}
#ifndef EVAL
int main() {
    int N, Q;
    cin >> N >> Q;
    inizia(N);
    for (int i = 0; i < Q; i++) {
        int X, Y; 
        cin >> X >> Y;
        cout << collega(X, Y) << "\n";
    }
}
#endif