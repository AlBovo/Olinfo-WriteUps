// Punti: 0.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
bool fa[20][20];
vector<pair<long long,long long>>q;
long long x, y;

long long trova(long long r){
    long long x1, y1;
    long long maxi = 0;
    long long l = q.size();
    for(long long i=r; i<l; i++){
        auto pos = q[i];
        if(pos.first != -1){
            x1 = pos.first; y1 = pos.second;
            if((fa[x1-2][y1] && fa[x1-1][y1]) || (fa[x1-1][y1] && fa[x1+1][y1]) || (fa[x1+1][y1] && fa[x1+2][y1]) ||
                (fa[x1-2][y1-2] && fa[x1-1][y1-1]) || (fa[x1-1][y1-1] && fa[x1+1][y1+1]) || (fa[x1+1][y1+1] && fa[x1+2][y1+2]) || 
                (fa[x1][y1-2] && fa[x1][y1-1]) || (fa[x1][y1-1] && fa[x1][y1+1]) || (fa[x1][y1+1] && fa[x1][y1+2]) ||
                (fa[x1+2][y1-2] && fa[x1+1][y1-1]) || (fa[x1+1][y1-1] && fa[x1-1][y1+1]) || (fa[x1-1][y1+1] && fa[x1-2][y1+2])
            ){ continue; }
            q[i] = {-1, 1};
            fa[pos.first][pos.second] = 1;
            maxi = max(maxi, trova(i+1));
            fa[pos.first][pos.second] = 0;
            q[i] = pos;
        }
    }
    return maxi + 1;
}

int main(){
    fin >> x >> y;
    x += 5; y += 5;
    for(long long i=5; i<x; i++){
        for(long long e=5; e<y; e++){
            fin >> fa[i][e];
            if(!fa[i][e]){
                q.push_back({i, e});
            }
        }
    }
    long long maxi = 0, l = q.size();
    for(long long i=0; i<l; i++){
        auto pos = q[i];
        if(pos.first != -1){
            q[i] = {-1, 1};
            fa[pos.first][pos.second] = 1;
            maxi = max(maxi, trova(0));
            fa[pos.first][pos.second] = 0;
            q[i] = pos;
        }
    }
    fout << maxi;
    return 0;
}
