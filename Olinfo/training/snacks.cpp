// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    int n, m, pos = 0, tot = 0; fin >> n >> m;
    vector<int>v(n);
    for(int &i:v){
        fin >> i;
    }
    sort(v.begin(), v.end());
    for(int pos = 0; pos<n;){
        if(pos == n-1){
            cout << tot+1;
            return 0;
        }
        if(v[pos] + v[pos+1] > m){
            tot += n-pos;
            cout << tot;
            return 0;
        }
        tot++;
        pos += 2;
    }
    cout << tot;
    return 0;
}