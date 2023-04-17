// Punti: 30.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");
int n, m;
vector<pair<int,bool>>v;

pair<int, unordered_set<int>> trova(int m1){
    pair<int, unordered_set<int>> maxi; maxi.first = 0;
    for(auto i : v){
        if(i.second && i.first <= m1){
            i.second = false;
            auto s = trova(m1-i.first);
            if(s.first + i.first > maxi.first){
                maxi.first = s.first + i.first;
                maxi.second = s.second;
                maxi.second.insert(i.first);
            }
            i.second = true;
        }
    }
    return maxi;
}


int main(){
    fin >> n >> m;
    v.resize(n);
    for(auto &i:v){
        fin >> i.first;
        i.second = true;
    }
    for(auto i : trova(m).second){
        fout << i << "\n";
    }
    return 0;
}