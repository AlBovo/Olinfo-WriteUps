// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main(){
    long long n; cin >> n;
    vector<long long> p(n), g(n);
    for(long long &i:p){
        cin >> i;
    }
    for(long long &i:g){
        cin >> i;
    }
    long long start = p[0], tot = g[0], pagati = 0;
    for(long long i=1; i<n; i++){
        if(p[i] <= start){
            pagati += tot * start;
            start = p[i];
            tot = g[i];
        }
        else{
            tot += g[i];
        }
    }
    cout << pagati + tot * start;
    return 0;
}