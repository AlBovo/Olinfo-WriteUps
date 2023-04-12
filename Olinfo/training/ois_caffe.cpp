#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, pr = 0, tot = 0; fin >> n;
    vector<pair<long long,long long>>v;
    for(int i=0; i<n; i++){
        int t, t1; fin >> t >> t1;
        v.push_back({t, 1});
        v.push_back({t1, -1});
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        if(i.second == -1){
            pr--;
        }
        else{
            tot += pr +1;
            pr++;
        }
    }
    fout << tot;
    return 0;
}
