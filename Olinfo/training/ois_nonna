// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
long long n, m, mini = 1e9;
vector<long long>v;
unordered_map<long long, long long>memo;
long long trova(long long p, vector<long long>&s){
    if(p >= m){
        memo[p] = p;
        mini = min(mini, p);
        return p;
    }
    if(!memo.count(p)){
        long long mini2 = 1e9;
        for(long long i=0; i<n; i++){
            if(s[i] == -1) continue;
            long long t = s[i];
            s[i] = -1;
            mini2 = min(mini2, trova(p+t, s));
            s[i] = t;
        }
        memo[p] = mini2;
    }
    return memo[p];
}

int main(){
    fin >> n >> m;
    v.resize(n);
    long long tot = 0;
    for(long long &i:v){
        fin >> i;
        tot += i;
    }
    trova(0, v);
    fout << mini;
    return 0;
}