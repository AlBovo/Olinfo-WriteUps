// Punti: 27.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
void pianifica(int R, int A[], int B[], int T[]){
    int l = 0, r = B[R-1];
    while(l <= r){
        int m = (l+r)/2, last = -1;
        bool valid = false;
        // cout << m << " ";
        
        for(int i=0; i<R; i++){
            if(i == 0){
                last = T[i] = A[i];
                continue;
            }
            if(i == R-1){
                valid = (B[i] - last < m);
                T[i] = B[i];
                continue;
            }
            if(B[i]-last < m){
                valid = true;
                break;
            }
            else if(A[i]-last > m) last = A[i];
            else last += m;
            T[i] = last;
        }
        if(valid) r = m - 1;
        else l = m + 1;
    }
    return;
}
#ifndef EVAL
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n; fin >> n;
    int A[n], B[n], T[n];
    for(int i=0; i<n; i++){
        int a, b; fin >> a >> b;
        A[i] = a;
        B[i] = b;
    }
    pianifica(n, A, B, T);
    for(int i=0; i<n; i++){
        fout << T[i] << " ";
    }
    return 0;
}
#endif