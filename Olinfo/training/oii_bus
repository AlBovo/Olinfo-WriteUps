// Punti: 37.0
#include <bits/stdc++.h>
#pragma GCC optmize("Ofast")
using namespace std;

struct node{
    int pos;
    int lin;
    int idx;
};
struct node1{
    int pos;
    int lin;
    int idx;
    int val;
};

int pianifica(int n, int l, vector<vector<int>>f){
    vector<vector<node>>v(n);
    node fr;
    vector<pair<int, int>>vp;
    for(int i=0; i<f.size(); i++){
        for(int e=0; e<f[i].size(); e++){
            if(e == 0){ continue; }
            fr.pos = f[i][e];
            fr.lin = i;
            fr.idx = e;
            v[f[i][e-1]].push_back(fr);
            if(f[i][e] == n-1){
                vp.push_back({n-1, i});
            }
        }
    }
    /*
    for(int i=0; i<v.size(); i++){
        cout << i << ": ";
        for(auto e:v[i]){
            cout << "{" << e.pos << "," << e.lin << "} ";
        }
        cout << "\n";
    }
    return 0;
    for(auto i:vp){
        cout << i.first << ", " << i.second << "\n";
    }
    */
    queue<node1>q; // posizione, linea
    map<pair<int, int>, int>p;
    node1 fr1;
    for(auto i:v[0]){
        fr1.pos = 0;
        fr1.lin = i.lin;
        fr1.idx = i.idx-1;
        fr1.val = 0;
        p[{0, i.lin}] = 0;
        q.push(fr1);
    }
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        if(p[{pos.pos, pos.lin}] < pos.val){ continue; }
        for(auto &i:v[pos.pos]){
            int tot = 0;
            if(pos.lin != i.lin){
                tot++;
            }
            else if(pos.idx > i.idx){
                tot++;
            }
            if(!p.count({i.pos, i.lin})){ p[{i.pos, i.lin}] = (int)(1e9); }
            if(p[{pos.pos, pos.lin}] + tot < p[{i.pos, i.lin}]){
                p[{i.pos, i.lin}] = p[{pos.pos, pos.lin}] + tot;
                fr1.pos = i.pos;
                fr1.lin = i.lin;
                fr1.idx = i.idx;
                fr1.val = p[{pos.pos, pos.lin}];
                //cout << pos.pos << "," << pos.lin << " >> " << i.pos << "," << i.lin << "\n";
                q.push(fr1);
            }
        }
    }
    int mini = (int)1e9;
    for(auto &i:vp){
        if(!p.count(i)){ continue; }
        mini = min(mini, p[i]);
    }
    if(mini == (int)1e9){ mini = -1; }
    return mini;
}

#ifndef EVAL
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, l; fin >> n >> l;
    vector<vector<int>>v(l);
    for(int i=0; i<l; i++){
        int t; fin >> t;
        for(int e=0; e<t; e++){
            int f; fin >> f;
            v[i].push_back(f);
        }
    }
    cout << pianifica(n, l, v);
    return 0;
}
#endif