// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int trova_massimo(int N, vector<int> V){
    return *max_element(V.begin(), V.end());
}
