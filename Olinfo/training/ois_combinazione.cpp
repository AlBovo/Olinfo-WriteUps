#include <fstream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    fstream::sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long n; fin >> n;
    vector<pair<long long,long long>>v;
    for(long long i=0; i<n; i++){
        long long t; fin >> t;
        v.push_back({t, i});
    }
    sort(v.begin(), v.end());
    long long tot = v[n-1].second;
    for(long long i=n-2; i>=0; i--){
        tot += abs(v[i].second - v[i+1].second);
    }
    fout << tot;
    return 0;
}
