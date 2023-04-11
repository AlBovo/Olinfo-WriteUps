#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int i=0; i<t; i++){
        int n, m, q; fin >> n >> m >> q;
        string s; fin >> s;
        vector<vector<char>>v(m);
        for(int e=0; e<s.size(); e++){
            v[0].push_back(s[e]);
        }
        fout << "Case #" << i+1 << ": ";
        for(int e=0; e<q; e++){
            char c; int t1, t2; fin >> c >> t1 >> t2;
            if(c == 'c'){
                if(t2 < v[t1].size()){
                    fout << v[t1][t2] << "";
                }
            }
            else{
                char k = v[t1].back();
                v[t1].pop_back();
                v[t2].push_back(k);
            }
        }
        fout << "\n";
    }
    return 0;
}