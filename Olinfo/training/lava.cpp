// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, m; fin >> n >> m;
    pair<int,int> mat[n+4][m+4];
    for(int i=0; i<n+4; i++){
        for(int e=0; e<m+4; e++){
            mat[i][e] = {1, 0};
        }
    }
    for(int i=2; i<n+2; i++){
        for(int e=2; e<m+2; e++){
            char t; fin >> t;
            if(t == '#'){
                mat[i][e] = {1, 0};
            }
            else{
                mat[i][e] = {0, (int)10e9};
            }
        }
    }
    mat[2][2].second = 0;
    /*
    for(int i=0; i<n+4; i++){
        for(int e=0; e<m+4; e++){
            cout << mat[i][e].first << "." << mat[i][e].second << " ";
        }
        cout << "\n";
    }
    */
    queue<pair<int,int>>q; q.push({2, 2});
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        if(!mat[pos.first-1][pos.second].first && mat[pos.first-1][pos.second].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first-1, pos.second});
            mat[pos.first-1][pos.second].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first-1][pos.second-1].first && mat[pos.first-1][pos.second-1].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first-1, pos.second-1});
            mat[pos.first-1][pos.second-1].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first][pos.second-1].first && mat[pos.first][pos.second-1].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first, pos.second-1});
            mat[pos.first][pos.second-1].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first+1][pos.second-1].first && mat[pos.first+1][pos.second-1].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first+1, pos.second-1});
            mat[pos.first+1][pos.second-1].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first+1][pos.second].first && mat[pos.first+1][pos.second].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first+1, pos.second});
            mat[pos.first+1][pos.second].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first+1][pos.second+1].first && mat[pos.first+1][pos.second+1].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first+1, pos.second+1});
            mat[pos.first+1][pos.second+1].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first][pos.second+1].first && mat[pos.first][pos.second+1].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first, pos.second+1});
            mat[pos.first][pos.second+1].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first-1][pos.second+1].first && mat[pos.first-1][pos.second+1].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first-1, pos.second+1});
            mat[pos.first-1][pos.second+1].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first-2][pos.second].first && mat[pos.first-2][pos.second].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first-2, pos.second});
            mat[pos.first-2][pos.second].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first+2][pos.second].first && mat[pos.first+2][pos.second].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first+2, pos.second});
            mat[pos.first+2][pos.second].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first][pos.second-2].first && mat[pos.first][pos.second-2].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first, pos.second-2});
            mat[pos.first][pos.second-2].second = mat[pos.first][pos.second].second+1;
        }
        if(!mat[pos.first][pos.second+2].first && mat[pos.first][pos.second+2].second > mat[pos.first][pos.second].second+1){
            q.push({pos.first, pos.second+2});
            mat[pos.first][pos.second+2].second = mat[pos.first][pos.second].second+1;
        }
    }
    fout << mat[n+1][m+1].second;
    return 0;
}