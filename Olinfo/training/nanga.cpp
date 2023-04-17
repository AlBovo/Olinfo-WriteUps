// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    int pos = 5000;
    unordered_map<int,int>m;
    for(int i=0; i<=n; i++){
        int t; fin >> t;
        cout << pos << endl;
        m[pos]++;
        pos += t;
    }
    pair<int,int>maxi = {0,-1};
    for(auto x:m){
        if(x.second > maxi.second){
            maxi.first = x.first;
            maxi.second = x.second;
        }
    }
    cout << maxi.first;
    fout << maxi.first;
    return 0;
}