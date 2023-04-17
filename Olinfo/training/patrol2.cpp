// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, m, l; fin >> n >> m >> l;
    vector<vector<long long>>v(n);
    vector<long long> p(n, (long long)10e8), c(l);
    for(long long i=0; i<m; i++){
        long long t, t1; fin >> t >> t1;
        v[t].push_back(t1);
        v[t1].push_back(t);
    }
    for(long long &i:c){
        fin >> i;
    }
    queue<pair<long long, long long>>q; q.push({0, 0}); p[0] = 0;
    while(!q.empty()){
        long long pos = q.front().first;
        long long pc = q.front().second % l;
        q.pop();
        if(pos == c[pc]){
            q.push({pos, pc+1});
            p[pos]++;
            continue;
        }
        for(long long i:v[pos]){
            if(p[i]>p[pos]+1){
                q.push({i, pc+1});
                p[i] = p[pos]+1;
            }
        }
    }
    cout << p[n-1];
    return 0;
}