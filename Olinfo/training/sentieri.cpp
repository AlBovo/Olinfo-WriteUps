// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t, a, b; 
    fin >> t >> a >> b;
    queue<int>q;
    vector<vector<pair<int,int>>>v(t+1);
    vector<int>p(t+1, (int)10e9);
    for(int i=0; i<a; i++){
        int t, t1, t2 = 0;
        fin >> t >> t1;
        v[t].push_back({t1, t2});
        v[t1].push_back({t, t2});
    }
    for(int i=0; i<b; i++){
        int t, t1, t2 = 1;
        fin >> t >> t1;
        v[t].push_back({t1, t2});
        v[t1].push_back({t, t2});
    }
    q.push(1);
    p[1] = 0;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(auto x:v[s]){
            if(p[x.first] > p[s]+x.second){
                p[x.first] = p[s]+x.second;
                q.push(x.first);
            }
        }
    }
    fout<<p[t];
    return 0;
}