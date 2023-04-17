// Punti: 70.0
#include <bits/stdc++.h>
#pragma optimize GCC("O3")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
unordered_map<int, bool> m;
map<vector<int>, bool>ma;

void trova(vector<int> &v){
    auto t = v;
    for(int i=0; i<v.size()-1; i++){
        if((v[i]+v[i+1]) % 2 != 0){
            t.erase(t.begin()+i, t.begin()+i+2);
            if(!ma.count(t)){
                ma[t] = true;
                if(t.size() == 1){
                    m[t[0]] = true;
                }
                else{
                    trova(t);
                }
            }
            t = v;
        }
    }
}

int main(){
    int n; fin >> n;
    vector<int>v(n);
    for(int &x:v){
        fin >> x;
    }
    trova(v);
    fout << m.size() << "\n";
    for(auto i:m){
        fout << i.first << " ";
    }
    return 0;
}