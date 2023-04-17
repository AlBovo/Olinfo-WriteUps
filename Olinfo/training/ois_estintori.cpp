// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

char matr[1000][1000];
bool m1[1000][1000];
int x, y;

void trova(int x1, int y1){
    m1[x1][y1] = false;
    if(x1 > 0){
        if(m1[x1-1][y1]){
            trova(x1-1, y1);
        }
    }
    if(x1 < x-1){
        if(m1[x1+1][y1]){
            trova(x1+1, y1);
        }
    }
    if(y1 > 0){
        if(m1[x1][y1-1]){
            trova(x1, y1-1);
        }
    }
    if(y1 < y-1){
        if(m1[x1][y1+1]){
            trova(x1, y1+1);
        }
    }
    return;
}

int main(){
    fin >> x >> y;
    queue<pair<int,int>>q;
    queue<pair<int,int>>q1;
    for(int i=0; i<x; i++){
        for(int e=0; e<y; e++){
            fin >> matr[i][e];
            if(matr[i][e] == '@') q.push({i, e});
            if(matr[i][e] == '@' || matr[i][e] == '.'){
                m1[i][e] = true;
                q1.push({i,e});
            }
            else{
                m1[i][e] = false;
            }
        }
    }
    while(!q.empty()){
        trova(q.front().first, q.front().second);
        q.pop();
    }
    int tot = 0;
    while(!q1.empty()){
        if(m1[q1.front().first][q1.front().second]){
            trova(q1.front().first, q1.front().second);
            tot++;
        }
        q1.pop();
    }
    fout << tot;
    return 0;
}