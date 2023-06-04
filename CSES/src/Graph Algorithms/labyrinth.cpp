#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<vector<bool>>mat;
    pair<int, int>start, end;
    int n, m; cin >> n >> m;
    mat.resize(n+4, vector<bool>(m+4, false));
    for(int i=2; i<=n+1; i++){
        for(int e=2; e<=m+1; e++){
            char t; cin >> t;
            if(t == 'A'){
                start = {i, e};
                mat[i][e] = true;
            }
            else if(t == 'B'){
                end = {i, e};
                mat[i][e] = true;
            }
            else{
                mat[i][e] = (t == '.');
            }
        }
    }
    queue<pair<int,int>>q;
    vector<vector<pair<long long, char>>>p(n+4, vector<pair<long long, char>>(m+4, {(long long)1e18, '\0'}));
    p[start.first][start.second] = {0, '\0'};
    q.push(start);
    while(!q.empty()){
        auto pos = q.front();
        long long tot = p[pos.first][pos.second].first;
        q.pop();
 
        if(tot+1 < p[pos.first+1][pos.second].first && mat[pos.first+1][pos.second]){
            p[pos.first+1][pos.second] = {tot+1, 'D'};
            q.push({pos.first+1, pos.second});
        }
        if(tot+1 < p[pos.first-1][pos.second].first && mat[pos.first-1][pos.second]){
            p[pos.first-1][pos.second] = {tot+1, 'U'};
            q.push({pos.first-1, pos.second});
        }
        if(tot+1 < p[pos.first][pos.second+1].first && mat[pos.first][pos.second+1]){
            p[pos.first][pos.second+1] = {tot+1, 'R'};
            q.push({pos.first, pos.second+1});
        }
        if(tot+1 < p[pos.first][pos.second-1].first && mat[pos.first][pos.second-1]){
            p[pos.first][pos.second-1] = {tot+1, 'L'};
            q.push({pos.first, pos.second-1});
        }
    }
    if(p[end.first][end.second].first != (long long)1e18){
        cout << "YES\n" << p[end.first][end.second].first << "\n";
        string val = "";
        pair<int, int> i = {end.first, end.second};
        while(i != start){
            char temp = p[i.first][i.second].second;
            val.push_back(temp);
            switch (temp){
                case 'U':
                    i.first += 1;
                    break;
                case 'D':
                    i.first -= 1;
                    break;
                case 'R':
                    i.second -= 1;
                    break;
                case 'L':
                    i.second += 1;
                    break;
            }
        }
        reverse(val.begin(), val.end());
        cout << val;
    }
    else{
        cout << "NO";
    }
    return 0;
}