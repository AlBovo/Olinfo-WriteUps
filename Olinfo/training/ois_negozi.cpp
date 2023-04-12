#include<bits/stdc++.h>
using namespace std; 
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.tie(0); fout.tie(0);
    int n, q; fin >> n >> q;
    vector<int>v(n);
    unordered_map<int, vector<int>>m;
    for(int i=0; i<n; i++){
        int t; fin >> t;
        v[i] = t;
        m[t].push_back(i);
    }
    for(int i=0; i<q; i++){
        int t, t1, mini = (int)10e8; fin >> t >> t1;
        for(int i:m[t1]){
            mini = min(mini, abs(t-i));
        }
        fout << mini << "\n";
    }
    return 0;
}