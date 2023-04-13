#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, k, k1, e = 0; fin >> n >> k;
    int V[n];
    for(int i=0; i<n; i++){
        fin >> V[i];
    }
    k1 = 1;
    while(k1 != k){
        k1 = V[k1-1];
        e++;
        if(e == n){
            fout << "-1";
            return 0;
        }
    }
    fout << e;
    return 0;
}

