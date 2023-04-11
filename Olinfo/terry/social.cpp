#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(NULL); fout.tie(NULL);
    int t; fin >> t;
    for(int c=0; c<t; c++){
        int n; fin >> n;
        vector<pair<int, int>>v;
        vector<int>s(n);
        for(int i=0; i<n; i++){
            int t; fin >> t;
            v.push_back({t, i});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for(int i=0; i<n; i++){
            for(int e=n-1; e>=0; e--){
                if(v[e].first > 0 && v[e].second != v[i].second){
                    v[e].first--;
                    s[v[i].second] = v[e].second;
                    e = -1;
                }
            }
        }
        fout << "Case #" << c+1 << ": ";
        for(int i : s){
            fout << i << " ";
        }
        fout << "\n";
    }
    return 0;
}