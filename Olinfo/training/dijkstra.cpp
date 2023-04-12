#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long N, P, part, arr;
    fin >> N >> P >> part >> arr;
    vector<vector<pair<long long,long long>>>V(N+1);
    queue<long long>q;
    vector<long long>p(N+1, (long long)10e14);
    p[part] = 0;
    q.push(part);

    for(long long i = 0; i < P; i++){
        long long t, t1, t2;
        fin >> t >> t1 >> t2;
        V[t].push_back({t1,t2});
    }

    while(!q.empty()){
        long long pos = q.front();
        q.pop();
        for(auto i:V[pos]){
            if(p[pos]+i.second < p[i.first]){
                p[i.first] = p[pos]+i.second;
                q.push(i.first);
            }
        }
    }

    fout << p[arr];
    return 0;
}