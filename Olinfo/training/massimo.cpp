// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int trova_massimo(int N, vector<int> V){
    return *max_element(V.begin(), V.end());
}