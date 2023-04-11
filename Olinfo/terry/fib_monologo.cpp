#include <bits/stdc++.h>
#pragma GCC optimze("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long t; fin >> t;
    for(long long e=0; e<t; e++){
        int n, tot = 0; fin >> n;
        vector<int>s(n), s1(n);
        for(int &i:s){
            fin >> i;
        }
        for(int &i:s1){
            fin >> i;
        }
        for(int i=0; i<n; i++){
            if(s[i] != s1[i]){
                tot++;
            }
        }
        fout << "Case #" << e+1 << ": " << tot << "\n";
    }

    return 0;
}
