// Punti: 10.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin>>n;
    vector<int>v(n);
    map<int, bool, greater<int>>m;
    m[1] = true;
    int maxi = 0;
    for(auto &x:v){
        fin >> x;
        maxi = max(maxi, x);
    }
    for(int i:v){
        for(int e=1; e*i<maxi; e++){
            m[e*i] = true;
        }
    }
    for(auto i: m){
        if(!m.count(m[i.first+(maxi - i.first-1)])){
            fout << i.first+(maxi - i.first-1);
            return 0;
        }
    }

    return 0;
}