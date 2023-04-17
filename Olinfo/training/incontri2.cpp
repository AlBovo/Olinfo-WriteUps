// Punti: 30.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool visita(int N, int A[]){
    int pos1 = 0, pos2 = N-1;
    while(pos1 <= pos2){
        if(pos1 == pos2){
            return 1;
        }
        if(A[pos1] < A[pos2]){
            pos1++;
            A[pos2] -= A[pos1];
            A[pos1] = 0;
        }
        else if(A[pos1] > A[pos2]){
            pos2--;
            A[pos1] -= A[pos2];
            A[pos2] = 0;
        }
        else if(A[pos1] == A[pos2]){
            pos1++; pos2--;
            A[pos1] = 0;
            A[pos2] = 0;
        }
    }
    return 0;
}
