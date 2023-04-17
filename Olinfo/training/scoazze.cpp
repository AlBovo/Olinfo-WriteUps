// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, m; fin >> n >> m;
    vector<long long>b;
    vector<long long>b1;
    for(long long i=0; i<n; i++){
        long long t; fin >> t;
        b.push_back(t);
        b1.push_back(t);
    }
    long long tot = 0;
    bool fatto;
    for(long long i=0; i<m; i++){
        fatto = false;
        long long t, t1; fin >> t >> t1;
        if(b[t] < t1){
            tot += b[t];
            b[t] = b1[t];
            fatto = true;
            b[t] -= t1;
        }
        else{
            b[t] -= t1;
        }

        if(i == m-1){
            for(long long i=0; i<n; i++){
                if(b[i] < b1[i]){
                    tot += b[i];
                }
            }
        }
    }
    fout << tot;
    return 0;
}
