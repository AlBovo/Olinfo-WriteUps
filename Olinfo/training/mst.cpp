// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
// Giuro che l'ho riscritto da capo
struct Arco{
    int start;
    int end;
    long long peso;
};
struct DSU{
    vector<long long> p, s;
    vector<pair<int, int>>edges;
    DSU(int n): p(n), s(n, 0){
        iota(p.begin(), p.end(), 0);
    }
    int find(int a){
        return (p[a] == a)? a : find(p[a]);
    }
    void onion(int a, int b, long long arco){
        int parA = find(a), parB = find(b);
        if(parA == parB) 
            return;
        
        if(s[parB] > s[parA]) 
            swap(parA, parB);
        edges.push_back({a, b});
        p[parB] = parA;
        s[parA] += s[parB] + arco;
    }
    long long mstWeight(){
        long long maxi = -1;
        for(int i=0; i<s.size(); i++) 
            maxi = max(maxi, s[i]);
        return maxi;
    }
};
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n, m; fin >> n >> m;
    vector<Arco>v(m);
    for(int i=0; i<m; i++){
        int a, b; long long c;
        fin >> a >> b >> c;
        v.push_back({a - 1, b - 1, c});
    }
    sort(v.begin(), v.end(), [](Arco a, Arco b){ 
        return a.peso < b.peso; 
    });
    DSU dsu = DSU(n);
    for(auto i : v){
        dsu.onion(i.start, i.end, i.peso);
    }
    fout << dsu.mstWeight() << "\n";
    for(auto i : dsu.edges){
        fout << i.first + 1 << " " << i.second + 1 << "\n";
    }
    return 0;
}