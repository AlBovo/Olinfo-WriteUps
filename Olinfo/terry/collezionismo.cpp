#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int f=0; f<t; f++){
        int n, m; fin >> n >> m;
        vector<int>v(n);
        for(int &i:v){
            fin >> i;
        }
        sort(v.begin(), v.end());
        vector<int>s;
        for(int i=0; i<n-1; i++){
            s.push_back(v[i+1]-v[i]);
        }
        sort(s.begin(), s.end());
        int tot = 0;
        for(int i=0; i<n-m; i++){
            tot += s[i];
        }
        fout << "Case #" << f+1 << ": " << tot << "\n";
    }
    return 0;
}