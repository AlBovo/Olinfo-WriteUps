#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<long long>v;

long long trova(long long e){
    long long f = lower_bound(v.begin(), v.end(), e)-v.begin();
    //cout << e << " " << v[f] << "\n";
    return v[f]-e;
}

int main(){
    v.push_back(2); v.push_back(3);
    for(long long i=4; i<=(int)(1e5)+1; i++){
        bool prim = true;
        for(long long e:v){
            prim = (i % e != 0);
            if(e > i || !prim) break;
        }
        if(prim){
            v.push_back(i);
        }
    }
    /*
    for(long long i:v){
        cout << i << " ";
    }
    */
    long long n, m; fin >> n >> m;
    vector<vector<long long>>mat(n, vector<long long>(m));
    vector<long long>rig(n), col(m);
    for(long long i=0; i<n; i++){
        for(long long e=0; e<m; e++){
            fin >> mat[i][e];
            long long mos = trova(mat[i][e]);
            rig[i] += mos;
            col[e] += mos;
        }
    }
    long long mini = (long long)1e9;
    for(long long i:rig){
        mini = min(i, mini);
    }
    for(long long i:col){
        mini = min(i, mini);
    }
    cout << mini;
    return 0;
}