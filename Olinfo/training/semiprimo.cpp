// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n = 0, f; fin >> n;
    vector<int>v;
    f = n;
    for(int i=2; i<f; i++){
        while(n % i == 0){
            v.push_back(i);
            n /= i;
        }
        if(v.size() > 2){
            fout << "-1";
            return 0;
        }
    }
    fout << v[0] << " " << v[1];
    return 0;
}