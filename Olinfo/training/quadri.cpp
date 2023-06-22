// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<long long>v(200000);
long long n, maxi;

bool trova(long long sl){
    unsigned long long tot = 0;
    for(long long i=0; i<sl; i++){
        tot += v[i];
    }
    if(tot > maxi){
        return false;
    }
    for(long long i=sl; i<n; i++){
        tot += v[i] - v[abs(i-sl)];
        if(tot > maxi){
            return false;
        }
    }
    return true;
}

int quadri(int N, long long M, int V[]){
    n = N; maxi = M;
    for(long long i=0; i<n; i++){
        v[i] = V[i];
    }
    long long l = 0, r = n;
    while(r - l > 1){
        long long m = (l+r)/2;
        if(trova(m)){
            l = m;
        }
        else{
            r = m;
        }
    }
    bool k = trova(l), k1 = trova(r);
    if(k1){
        return r;
    }
    return l;
}

#ifndef EVAL
int main(){
    int n, m; fin >> n >> m;
    int v[n];
    for(int i=0; i<n; i++){
        fin >> v[i];
    }
    cout << quadri(n, (long long)m, v);
    return 0;
}
#endif