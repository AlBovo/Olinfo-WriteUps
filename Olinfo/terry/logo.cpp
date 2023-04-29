#include <bits/stdc++.h>
#pragma GCC optimze("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long t; fin >> t;
    for(long long e=0; e<t; e++){
        int n, m; fin >> n >> m;
        int mat[n][m]; // 0,2: deve rimanere così 1: deve cambiare
        for(int i=0; i<n; i++){
            string t; fin >> t;
            for(int f=0; f<m; f++){
                if(t[f] == 'N'){
                    mat[i][f] = 1;
                }
                else{
                    mat[i][f] = 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            string t; fin >> t;
            for(int f=0; f<m; f++){
                if(t[f] == 'N'){
                    mat[i][f] += 1;
                }
            }
        }
        /*for(int i=0; i<n; i++){
            for(int f=0; f<m; f++){
                cout << mat[i][f] << " ";
            }
            cout << endl;
        }*/
        
        int destra = 0, giu = 0, sinistra = m, su = n;
        bool entrato = false;
        for(int i=0; i<n; i++){ // su giu
            for(int f=0; f<m; f++){ // destra sinistra
                if(mat[i][f] == 1){
                    entrato = true;
                    destra = max(destra, f);
                    sinistra = min(sinistra, f);
                    giu = max(giu, i);
                    su = min(su, i);
                }
            }
        }
        // cout << destra << " " << sinistra << " " << su << " " << giu << " ";
        if(entrato){
            fout << "Case #" << e+1 << ": " << (destra-sinistra+1)*(giu-su+1) << "\n";
        }
        else{
            fout << "Case #" << e+1 << ": " << 0 << "\n";
        }
    }
    return 0;
}
