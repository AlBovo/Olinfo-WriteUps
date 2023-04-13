#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long int N, pre = 1, tot = 1; fin >> N;
    for(int i=0; i<N; i++){
        long long int temp; fin >> temp;
        tot += pre * temp;
        pre = pre * temp;
    }
    cout << tot;
    return 0;
}