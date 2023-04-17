// Punti: 0.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    int n; fin >> n;
    for(int i=0; i<n; i++){
        int xa, ya, xb, yb, xs, ys, r; fin >> xa >> ya >> xb >> yb >> xs >> ys >> r;
        double sas = sqrt(pow(abs(xa-xb), 2) + pow(abs(ya-yb), 2));
        fout << fixed << setprecision(6) << sas << "\n";
    }
    return 0;
}