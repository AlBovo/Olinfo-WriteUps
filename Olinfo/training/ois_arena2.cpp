#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, k; fin >> n >> k;
    vector<queue<int>>v(n);
    vector<int>p(n, 0);
    for(int i=0; i<k; i++){
        int x, y; fin >> x >> y;
        if(x == y){
            p[v[x].back()]--;
            v[x].pop();
        }
        else{
            p[x]++;
            v[y].push(x);
        }
    }
    for(int i:p){
        fout << i << " ";
    }
    return 0;
}