// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<int>v(n*2);
    unordered_map<int,int>m;
    for(int &x : v){
        fin >> x;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        if(v[i] != 0)
            m[v[i]]++;
    }
    for(auto i : m){
        if(i.second == 1){
            fout << i.first;
            return 0;
        }
    }

    return 0;
}