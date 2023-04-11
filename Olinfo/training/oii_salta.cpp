#include <bits/stdc++.h>
#pragma GCC optimize("O2");
using namespace std;
typedef long long ll;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    ll n, l = 1; fin >> n;
    vector<ll>V(n);
    map<ll, bool>m;
    vector<ll>non_trov;
    for(ll i=1; i<=n; i++) fin >> V[i];
    while(!m.count(l) && l <= n && l >= 1){
        m[l] = true;
        l = ((l + V[l]) % n) + 1;
    }
    for(ll i=1; i<=n; i++){
        if(!m.count(i)){
            non_trov.push_back(i);
        }
    }
    fout << non_trov.size() << "\n";
    for(ll i : non_trov) fout << i << " ";
    return 0;
}