// Punti: 10.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    map<vector<int>, int>ma;
    int n, m; fin >> n >> m;
    for(int i=0; i<n; i++){
        string temp; fin >> temp;
        vector<int>v(m, 0);
        for(int e=0; e<temp.size()-1; e++){
            v[e] = abs(temp[e+1] - temp[e]);
        }
        ma[v]++;
    }
    int maxi = 0;
    for(auto i : ma){
        if(i.second > maxi){
            maxi = i.second;
        }
    }
    fout << maxi;
    return 0;
}