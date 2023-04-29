#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int i=0; i<t; i++){
        int a, b; fin >> a >> b;
        for(int e=0; e<2; e++){
            int t, t1; fin >> t >> t1;
            a ^= t;
            b ^= t1;
        }
        fout << "Case #" << i+1 << ": " << a << " " << b << "\n";
    }
    return 0;
}