// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    priority_queue<pair<int, string>>pq;
    int n, m; fin >> n >> m;
    vector<pair<int, string>>p;
    for(int i=0; i<2; i++){
        for(int e=0; e<n; e++){
            if(!i){
                int t; fin >> t;
                p.push_back({t, ""});
            }
            else{
                string st; fin >> st;
                p[e].second = st;
            }
        }
    }
    for(auto i:p){
        pq.push(i);
    }
    unordered_map<string, int>ma;
    ma["bipasso"] = 0; ma["L16"] = 0; ma["L10"] = 0;
    for(int i=0; i<m; i++){
        string st; fin >> st;
        ma[st]++;
    }
    int tot = 0;
    while(!pq.empty()){
        if(ma[pq.top().second] > 0){
            ma[pq.top().second]--;
            tot += pq.top().first;
        }
        else if(ma["bipasso"] > 0){
            ma["bipasso"]--;
            tot += pq.top().first;
        }
        pq.pop();
    }
    fout << tot;
    return 0;
}