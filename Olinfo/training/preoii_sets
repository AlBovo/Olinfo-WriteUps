// Punti: 41.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
map<vector<int>, long long> m;
int conta(int N, vector<int> V){
    int maxi = 0;
    if(V.size() < 3){
    	m[V] = 0;
        return 0;
    }
    if(m.count(V)){
    	return m[V];
    }
    auto v = V;
    for(int i=0; i<v.size()-2; i++){
        if((int)(V[i]^V[i+1]^V[i+2]) == 0){
            v.erase(v.begin()+i, v.begin()+i+3);
            maxi = max(maxi, 3+conta(N, v));
        }
        v = V;
    }
    m[V] = maxi;
    return maxi;
}
