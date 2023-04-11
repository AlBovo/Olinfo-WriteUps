#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main(){
    int N, K, m = 0, maxm;fin >> N >> K;
    int V[N];
    for(int i = 0; i < N; i++){
        fin >> V[i];
    }
    for(int e = 0; e < K; e++){
        m += V[e];
    }
    maxm = m;
    for(int i = 0; i < N - K; i++){
        m -= V[i];
        m += V[i+K];
        if(m < maxm){
            maxm = m;
        }
    }
    fout << maxm;
    return 0;
}
