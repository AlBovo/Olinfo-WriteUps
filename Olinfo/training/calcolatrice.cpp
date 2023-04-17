// Punti: 0.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<int>v(n);
    for(int &i:v){
        fin >> i;
    }
    int maxi = 0;
    for(int i=0; i<n; i++){
        vector<bool>b(n, false);
        int pos = i, t = 0;
        while(!b[pos]){
            t++;
            b[pos] = true;
            cout << pos << "\n";
            pos = v[pos];
        }
        cout << t << " " << i << "\n";
        if(t > maxi){
            maxi = t;
        }
    }
    cout << maxi;

    return 0;
}
