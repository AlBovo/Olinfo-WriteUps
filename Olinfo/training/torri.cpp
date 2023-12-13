// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>v;
vector<vector<int>>dp;

int calcola(int pos, int Max){
    if(pos == (int)v.size()) return 0;
    if(dp[pos][Max] != -1) return dp[pos][Max];

    int nonPr = calcola(pos+1, Max) + v[pos].second;
    int Pr = (Max > v[pos].first)? calcola(pos+1, v[pos].first) : 1e9;

    return dp[pos][Max] = min(nonPr, Pr);
}

// Coccodrillo1234
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n; fin >> n;
    dp.resize(n, vector<int>(1002, -1));
    v.resize(n);
    for(auto &i:v){
        fin >> i.first >> i.second;
    }

    fout << calcola(0, 1000);
    return 0;
}