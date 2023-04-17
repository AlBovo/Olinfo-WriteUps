// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<long long>v(31, -1);

long long fib(long long n){
    if(n == 0 || n == 1){
        return n;
    }
    int i = v[n-1], t = v[n-2];
    if(i != -1 && t != -1) return t+i;
    else if(i != -1 && t == -1){
        v[n-2] = fib(n-2);
        return i+v[n-2];
    }
    else if(i == -1 && t != -1){
        v[n-1] = fib(n-1);
        return t+v[n-1];
    }
    else{
        v[n-1] = fib(n-1);
        v[n-2] = fib(n-2);
        return v[n-1]+v[n-2];
    }
}

int main(){
    long long boh = fib(31);
    long long n; fin >> n;
    string c = "";
    auto i = upper_bound(v.begin(), v.end(), n)-v.begin();
    bool t = false, primo = false;
    long long tot = 0;
    for(long long e=i-1; e>=1; e--){
        if(v[e] <= n){
            primo = true;
            c+="1";
            n-=v[e];
        }
        else{
            c+="0";
        }
    }
    for(long long i=c.size()-1; i>=0; i--){
        fout << c[i];
    }
    return 0;
}