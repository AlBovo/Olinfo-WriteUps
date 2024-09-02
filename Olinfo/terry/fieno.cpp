#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long t; fin >> t;
    for(long long e=0; e<t; e++){
        long long n; fin >> n;
        vector<long long>v(n);
        for(long long &i:v) fin >> i;
        long long idx = 0, pro = -1;
        for(long long i=1; i<n-1; i++){
            if(v[i-1] < v[i] && v[i] > v[i+1] && min(v[i] - v[i-1], v[i] - v[i+1]) > pro){
                pro = min(v[i] - v[i-1], v[i] - v[i+1]);
                idx = i;
            }
        }
        fout << "Case #" << e+1 << ": " << (idx == 0 ? -1 : idx) << "\n";
    }
    return 0;
}