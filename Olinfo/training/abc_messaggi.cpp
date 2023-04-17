// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, m; fin >> n >> m;
    map<string, vector<string>>inv;
    map<string, vector<string>>ric;
    for(int i=0; i<n; i++){
        string t, t1; fin >> t >> t1;
        inv[t].push_back(t1);
        ric[t1].push_back(t);
    }
    for(int i=0; i<m; i++){
        string t, t1; fin >> t >> t1;
        if(t1 == "INVIATI"){
            fout << inv[t].size() << " ";
            for(string e:inv[t]){
                fout << e << " ";
            }
            fout << "\n";
        }
        else if(t1 == "RICEVUTI"){
            fout << ric[t].size() << " ";
            for(string e:ric[t]){
                fout << e << " ";
            }
            fout << "\n";
        }
    }
    return 0;
}