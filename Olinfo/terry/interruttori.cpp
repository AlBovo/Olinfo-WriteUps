#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

/*
void dfs(long long pos, set<long long>vis, vector<vector<long long>>&v, vector<long long>&p){
    vis.insert(pos);
    for(long long i : v[pos]){
        if((!vis.count(i)) && p[i] > p[pos]+1){
            p[i] = p[pos]+1;
            dfs(i, vis, v, p);
        }
    }
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(0); fout.tie(0);
    long long c; fin >> c;
    for(long long s=0; s<c; s++){
        long long n, a, b;
        fin >> n >> a >> b;
        queue<long long>q;
        vector<vector<long long>>v(n);
        vector<long long>p(n, (long long)10e19);
        for(long long i=0; i<a; i++){
            long long t; fin >> t;
            q.push(t);
            p[t] = 1;
        }
        for(long long i=0; i<b; i++){
            long long t1, t2; fin >> t1 >> t2;
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            for(int i : v[pos]){
                if(p[i] > p[pos]+1){
                    p[i] = p[pos]+1;
                    q.push(i);
                }
            }
        }
        pair<long long, long long> maxi = {-1, -1};
        for(long long i=0; i<p.size(); i++){
            if(p[i] > maxi.first){
                maxi.first = p[i];
                maxi.second = i;
            }
        }
        fout << "Case #" << s+1 << ": " << maxi.second << " " << maxi.first << "\n";
    }
    return 0;
}