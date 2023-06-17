// Punti: 41.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int conta(int N, vector<int> V){
    int maxi = 0;
    if(V.size() < 3){
        return 0;
    }
    auto v = V;
    for(int i=0; i<v.size()-2; i++){
        if((int)(V[i]^V[i+1]^V[i+2]) == 0){
            v.erase(v.begin()+i, v.begin()+i+3);
            maxi = max(maxi, 3+conta(N, v));
        }
        v = V;
    }
    return maxi;
}