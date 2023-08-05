// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

long long aggiorna(int N, vector<int> A, vector<int> B){
    long long tot = 0;
    for(int i=A.size()-2; i>=0; i--){
        tot += (int)((A[i+1]-A[i])/B[i]);
        A[i] += (int)((A[i+1]-A[i])/B[i]) * B[i];
    }
    return tot;
}