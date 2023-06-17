// Punti: 80.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n; fin >> n;
    vector<long double>d(n);
    for(int i=0; i<n; i++){
        int t, t1, t2;
        fin >> t >> t1 >> t2;
        d[i] = (long double)sqrt((long long)(pow(t,2)+pow(t1,2)+pow(t2,2)));
    }
    sort(d.begin(), d.end());
    long double r;
    fin >> r;
    for(long long i=0; i<r; i++){
        long double t; fin >> t;
        long double it = (long double)(upper_bound(d.begin(), d.end(), t) - d.begin());
        fout << (long double)it << "\n";
    }
    return 0;
}