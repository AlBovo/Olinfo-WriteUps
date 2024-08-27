// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, pos, tot, maxi = 1; fin >> n;
    vector<int>v(n), vis(n, false);
    for(int &i: v)
        fin >> i;

    for(int i=0; i<n; i++){
        if(vis[i])
            continue;
        unordered_map<int, int>ve;
        pos = i;
        tot = 0;
        bool flag = false;
        while(ve.count(pos) == 0){
            if(flag = vis[pos])
                break;
            ve[pos] = tot;
            vis[pos] = true;
            pos = v[pos];
            tot++;
            // cerr << pos << "\n";
        }
        if(!flag)
            maxi = max(maxi, tot - ve[pos]);
    }
    fout << maxi;
    return 0;
}