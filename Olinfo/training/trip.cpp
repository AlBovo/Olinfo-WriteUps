// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, s, a; fin >> n >> s >> a;
    long long r; fin >> r;
    queue<long long>q;
    vector<long long>p(n+1, (long long)10e8);
    vector<vector<vector<long long>>>v(r+1);
    for(long long i=0; i<r; i++){
        long long t, t1, t2, t3;
        fin >> t >> t1 >> t2 >> t3;
        vector<long long>s;
        s.push_back(t);
        s.push_back(t2);
        s.push_back(t1);
        s.push_back(t3);
        v[t].push_back(s);
    }
    q.push(s);
    p[s] = 0;
    while(!q.empty()){
        long long pos = q.front();
        q.pop();
        for(auto i:v[pos]){
            if(p[i[1]] > i[3] && i[2] >= p[pos]){
                p[i[1]] = i[3];
                q.push(i[1]);
            }
        }
    }
    if(p[a] == (long long)10e8){
        fout << "IMPOSSIBLE";
    }
    else{
        fout << p[a];
    }
    return 0;
}