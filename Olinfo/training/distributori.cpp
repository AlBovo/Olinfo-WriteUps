// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, m, k; fin >> n >> m >> k;
    vector<int>v(n);
    for(auto &x : v){
        fin >> x;
    }
    int tot = 0, last = 0;
    for(int i=0; i<n; i++){
        if(i == n-1 && m < k - last){
            tot++;
            cout << v[i] << " " << tot << " " << k-last <<"\n";
        }
        if(i == n-1){
            cout << tot;
            fout << tot;
            return 0;
        }
        if(m < v[i+1]-last){
            last = v[i];
            tot++;
            cout << v[i] << " " << tot <<"\n";
        }
    }
    return 0;
}