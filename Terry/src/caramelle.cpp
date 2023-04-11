#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<numeric>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int i=0; i<t; i++){
        int n, lm = 1; fin >> n;
        for(int e=0; e<n; e++){
            int k; fin >> k;
            lm = lcm(lm,k);
        }
        fout << "Case #" << i+1 << ": " << lm << "\n";
    }
    return 0;
}