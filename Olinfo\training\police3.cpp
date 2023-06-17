// Punti: 100.0
#include <bits/stdc++.h>
#pragma optimize GCC("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int n;
vector<int>v;
map<pair<int,int>, int>m;

int trova(int pos, bool c){ // 0 aspettato, 1 non aspettato
    if(pos == n){
        return 0;
    }
    if(c){
        if(!m.count({pos, 0})){
            m[{pos, 0}] = v[pos] + trova(pos+1, 0);
        }
        return m[{pos, 0}];
    }
    else{
        if(!m.count({pos, 1})){
            m[{pos, 1}] = min(v[pos]+trova(pos+1, 0), trova(pos+1, 1));
        }
        return m[{pos, 1}];
    }
}

int main(){
    fin >> n;
    v.resize(n);
    for(int &x : v){
        fin >> x;
    }
    fout << min(v[0] + trova(1, 0), trova(1, 1));
    return 0;
}