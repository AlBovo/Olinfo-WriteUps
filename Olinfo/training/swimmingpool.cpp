// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<int>v(n);
    for(int &i : v){
        fin >> i;
    }
    int mini = 10e6+1;
    for(int i : v){
        mini = min(max(v[n-1]-i, i -v[0]), mini);
    }
    fout << mini;
    return 0;
}