#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n; fin >> n;
    vector<pair<int, set<int>>>v(n);
    queue<int>q;
    for(int i=0; i<n; i++){
        int k, s; fin >> k >> s;
        v[i].first = s;
        for(int e=0; e<k; e++){
            int t; fin >> t;
            v[t].second.insert(i);
        }
        if(s == 0){
            q.push(i);
        }
    }
    int tot = 0;
    while(!q.empty()){
        tot++;
        int pos = q.front();
        q.pop();
        for(int i: v[pos].second){
            v[i].first--;
            if(v[i].first == 0){
                q.push(i);
            }
        }
    }
    fout << tot;
    return 0;
}
