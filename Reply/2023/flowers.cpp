#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<pair<long long, long long>>v;
set<pair<long long, long long>>s;
map<set<pair<long long, long long>>, long long>ma;
long long w, h, f, g;

long long calcolaMin(){
    long long mini = (long long)10e8;
    vector<pair<long long, long long>>ve;
    for(auto &i:s){
        ve.push_back(i);
    }
    for(long long i=0; i<ve.size(); i++){
        for(long long e=i+1; e<ve.size(); e++){
            mini = min(mini, abs(ve[i].first - ve[e].first)+abs(ve[i].second - ve[e].second));
        }
    }
    return mini;
}

long long trova(long long num){
    if(num == f){
        return calcolaMin();
    }
    if(!ma.count(s)){
        long long m = -1;
        for(auto i:v){
            if(!s.count(i)){
                s.insert(i);
                m = max(m, trova(num+1));
                s.erase(i);
            }
        }
        ma[s] = m;
    }
    return ma[s];
}
    

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long t; fin >> t;
    for(long long i=0; i<t; i++){
        fin >> w >> h >> f >> g;
        for(long long e=0; e<g; e++){
            long long t, t1; fin >> t >> t1;
            v.push_back({t, t1});
        }
        /*for(long long e=0; e<w; e++){
            for(long long j=0; j<h; j++){
                cout << mat[j][e] << " ";
            }
            cout << endl;
        } CORRETTO */
        cerr << "Case #" << i+1 << ": " << trova(0) << "\n";
        v.clear();
        ma.clear();
    }
    return 0;
}
