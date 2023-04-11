#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long t; fin >> t;
    for(long long i=0; i<t; i++){
        long long n, bf, bi, tot = 0; fin >> n >> bf >> bi;
        vector<pair<long long, long long>>v(n); // rendita / costo
        for(auto &i:v){
            long long t, t1; fin >> t >> t1;
            i.first = t1-t;
            i.second = t;
        }
        sort(v.begin(), v.end(), greater<pair<long long,long long>>());
        while(bi < bf){
            if(v[0].second <= bi){
                tot += ceil((bf-bi)/v[0].first);
                break;
            }
            for(auto i:v){
                if(i.second <= bi){
                    bi += i.first;
                    tot++;
                    break;
                }
            }
        }
        fout << "Case #" << i+1 << ": " << tot+1 << "\n";
    }
    return 0;
}
