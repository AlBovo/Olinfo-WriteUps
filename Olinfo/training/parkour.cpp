// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
typedef vector<int> vint;
ifstream fin("input.txt");
ofstream fout("output.txt");
int n;

bool trova(int k, vint &s, vint &a, vint &b){
    vector<int>so(n+2);
    so[n+1] = 0;
    so[n] = 1;
    for(int i=n-1; i>=0; --i){
        so[i] = so[i+1];
        if(s[i] > k){
            continue;
        }
        if(so[i+a[i]]-so[i+b[i]+1] > 0){
            so[i]++;
        }
    }
    return so[0] - so[1];
}

int salta(int N, vint S, vint A, vint B){
    n = N;
    int l = 0, r = 1e6;
    while(l != r){
        int m = (l+r)/2;
        if(trova(m, S, A, B)){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    return l;
}

#ifndef EVAL
int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    int n; fin >> n;
    vint S, A, B;
    for(int i=0; i<n; i++){
        int a, b, c; fin >> a >> b >> c;
        S.push_back(a);
        A.push_back(b);
        B.push_back(c);
    }
    cout << salta(n, S, A, B);
    return 0;
}
#endif