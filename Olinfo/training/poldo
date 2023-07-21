// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int>v, mang;

int dp_ric(int pos, int ult){
    if(pos >= v.size()){ return 0; }
    if(mang[pos] != -1 && v[pos] < ult){ return max(mang[pos], dp_ric(pos+1, ult)); }
    if(v[pos] >= ult){ return dp_ric(pos+1, ult); }
    if(v[pos] < ult){
        mang[pos] = dp_ric(pos+1, v[pos])+1;
        return max(mang[pos], dp_ric(pos+1, ult));
    }
}

int main(){
    int n; fin >> n;
    v.resize(n);
    mang.resize(n, -1);
    for(int &i:v){
        fin >> i;
    }
    fout << dp_ric(0, (int)1e4+1);
    return 0;
}