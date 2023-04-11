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
        int n, m, c; fin >> n >> m >> c;
        fout << "Case #" << e+1 << ": " << min(n*m, c) << "\n";
    }

    return 0;
}
