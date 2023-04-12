#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int N, M, primo, t; fin >> N >> M;
    for(int i=0; i<N; i++){
        fin >> t;
        if(!i) primo = t;
    }
    for(int i=0; i<M; i++){
        int A, B; fin >> A >> B;
        if(B == primo) primo = A;
    }
    fout << primo;
    return 0;
}