#include <bits/stdc++.h>
#pragma GCC optimze("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    int t; fin >> t;
    for(int i=0; i<t; i++){
        int n, tot = 0; fin >> n;
        for(int i=1; i<=4; i++){
            int k; fin >> k;
            if(k <= n){
                tot += 4 * k;
                n -= k;
            }
            else if(n > 0){
                k -= n;
                tot += 4*n + i * k;
                n = 0;
            }
            else{
                tot += k * i;
            }
        }
        fout << "Case #" << i+1 << ": " << tot << "\n";
    }
    
    return 0;
}
