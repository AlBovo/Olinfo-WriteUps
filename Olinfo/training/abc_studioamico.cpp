#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

bool associabili(int N, int voti2[], int voti5[]){
    sort(voti2, voti2+N);
    sort(voti5, voti5+N);
    for(int i=0; i<N; i++){
        if(voti5[i] <= voti2[i]){
            return false;
        }
    }
    return true;
}