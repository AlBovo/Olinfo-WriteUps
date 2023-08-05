// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, maxi = -1e9; fin >> n;
    for(int i=0; i<n; i++){
        int t; fin >> t;
        maxi = max(maxi, t);
    }
    fout << maxi;
    return 0;
}