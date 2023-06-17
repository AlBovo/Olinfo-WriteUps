// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int n;
vector<pair<int,int>>v;
int trova(vector<bool>s, int first){
    int maxi = 0;
    for(int i=0; i<n; i++){
        if(first < 0){
            s[i] = true;
            maxi = max(maxi, trova(s, v[i].first)+1);
            maxi = max(maxi, trova(s, v[i].second)+1);
            s[i] = false;
        }
        else if(!s[i]){
            if(v[i].first == first){
                s[i] = true;
                maxi = max(maxi, trova(s, v[i].second)+1);
                s[i] = false;
            }
            if(v[i].second == first){
                s[i] = true;
                maxi = max(maxi, trova(s, v[i].first)+1);
                s[i] = false;
            }
        }
    }
    return maxi;
}

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    fin >> n;
    v.resize(n);
    for(auto &i:v){
        fin >> i.first >> i.second;
    }
    vector<bool>s(n, false);
    fout << trova(s, -1);
    return 0;
}