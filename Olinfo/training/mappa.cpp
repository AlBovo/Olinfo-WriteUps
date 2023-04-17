// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    set<pair<int,int>>m;
    map<pair<int,int>,int>ma;
    queue<pair<int,int>>q; q.push({0,0});
    for(int i=0; i<n; i++){
        for(int e=0; e<n; e++){
            char t; fin >> t;
            if(t == '*'){
                m.insert({i,e});
                ma[{i,e}] = (int)10e9;
            }
        }
    }
    ma[{0,0}] = 0;
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        if(m.count({pos.first-1, pos.second}) && ma[{pos.first-1, pos.second}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first-1, pos.second}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first-1, pos.second});
        }
        if(m.count({pos.first-1, pos.second-1}) && ma[{pos.first-1, pos.second-1}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first-1, pos.second-1}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first-1, pos.second-1});
        }
        if(m.count({pos.first, pos.second-1}) && ma[{pos.first, pos.second-1}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first, pos.second-1}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first, pos.second-1});
        }
        if(m.count({pos.first+1, pos.second-1}) && ma[{pos.first+1, pos.second-1}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first+1, pos.second-1}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first+1, pos.second-1});
        }
        if(m.count({pos.first+1, pos.second}) && ma[{pos.first+1, pos.second}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first+1, pos.second}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first+1, pos.second});
        }
        if(m.count({pos.first+1, pos.second+1}) && ma[{pos.first+1, pos.second+1}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first+1, pos.second+1}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first+1, pos.second+1});
        }
        if(m.count({pos.first, pos.second+1}) && ma[{pos.first, pos.second+1}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first, pos.second+1}] = ma[{pos.first,pos.second}]+1;
            q.push({pos.first, pos.second+1});
        }
        if(m.count({pos.first-1, pos.second+1}) && ma[{pos.first-1, pos.second+1}] > ma[{pos.first, pos.second}]+1){
            ma[{pos.first-1, pos.second+1}] = ma[{pos.first, pos.second}]+1;
            q.push({pos.first-1, pos.second+1});
        }
    }
    fout << ma[{n-1,n-1}]+1;
    return 0;
}