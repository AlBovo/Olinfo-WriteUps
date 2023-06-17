// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long n, t; fin >> n >> t;
    vector<long long>v(n);
    for(long long &i:v){
        fin >> i;
    }
    for(long long i=0; i<t; i++){
        long long x, d; fin >> x >> d;
        long long pos = upper_bound(v.begin(), v.end(), x) - v.begin() - d;
        if(pos+1 > n-pos){
            fout << "0 ";
        }
        else if(pos+1 < n-pos){
            fout << "1 ";
        }
        else{
            fout << !d << " ";
        }
    }
    return 0;
}