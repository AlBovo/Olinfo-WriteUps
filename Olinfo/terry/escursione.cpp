#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    int minPath;
};

vector<vector<Node>>v;

int calculateValue(int v1, int v2, int v3){
    return max(v3, abs(v1 - v2));
}

void solve(int t){
    int h, w; cin >> h >> w;
    v.clear();
    v.resize(h, vector<Node>(w, (Node){0, (int)1e9}));
    for(auto &i : v)
        for(auto &e : i)
            cin >> e.value;

    priority_queue<pair<int, pair<int, int>>>pq;
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        int peso = pq.top().first, temp;
        auto pos = pq.top().second;
        pq.pop();

        if(v[h-1][w-1].minPath != (int)1e9)
            break;

        if(peso * -1 < v[pos.first][pos.second].minPath)
            v[pos.first][pos.second].minPath = peso * -1;
        else
            continue;
        
        if(pos.first > 0 && (temp = calculateValue(v[pos.first - 1][pos.second].value, v[pos.first][pos.second].value, v[pos.first][pos.second].minPath)) < v[pos.first - 1][pos.second].minPath)
            pq.push({temp * -1, {pos.first - 1, pos.second}});
        if(pos.first < h-1 && (temp = calculateValue(v[pos.first + 1][pos.second].value, v[pos.first][pos.second].value, v[pos.first][pos.second].minPath)) < v[pos.first + 1][pos.second].minPath)
            pq.push({temp * -1, {pos.first + 1, pos.second}});
        if(pos.second > 0 && (temp = calculateValue(v[pos.first][pos.second - 1].value, v[pos.first][pos.second].value, v[pos.first][pos.second].minPath)) < v[pos.first][pos.second - 1].minPath)
            pq.push({temp * -1, {pos.first, pos.second - 1}});
        if(pos.second < w-1 && (temp = calculateValue(v[pos.first][pos.second + 1].value, v[pos.first][pos.second].value, v[pos.first][pos.second].minPath)) < v[pos.first][pos.second + 1].minPath)
            pq.push({temp * -1, {pos.first, pos.second + 1}});
    }

    cout << "Case #" << t << ": " << v[h-1][w-1].minPath << "\n";
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++)
        solve(i+1);
    return 0;
}