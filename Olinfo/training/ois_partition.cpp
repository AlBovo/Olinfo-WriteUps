#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int>fenwick;

void update(int idx, int delta){
    for(; idx < fenwick.size(); idx+=idx&-idx){
        fenwick[idx] += delta;
    }
}
int sum(int idx){
    int som = 0;
    while(idx > 0){
        som += fenwick[idx];
        idx-=idx&-idx;
    }
    return som;
}

int main(){
    int n; fin >> n;
    fenwick.resize(n+1);
    vector<int>v(n);
    for(int &i:v){
        fin >> i;
    }
    for(int i=1; i<=n; i++){
        fout << v[i-1]-1 - sum(v[i-1]-1) + (sum(n) - sum(v[i-1])) << " ";
        update(v[i-1], 1);
    }
    return 0;
}