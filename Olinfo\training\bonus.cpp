// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, maxi = 0, sum1 = 0, sum2 = 0;
    fin >> n;
    vector<pair<long long, long long>>v(n);
    for(auto &x:v){
        fin >> x.first >> x.second;
        sum1+=x.first;
        sum2+=x.second;
    }
    long long maxi1 = sum1 - v[0].first, maxi2 = sum2-v[0].second;
    for(int i=1; i<n; i++){
        long long t = sum1 - v[i].first, t2 = sum2 - v[i].second;
        if(t * maxi2 > t2 * maxi1){
            maxi = i;
            maxi1 = t;
            maxi2 = t2;
        }
    }
    cout << maxi;
    return 0;
}