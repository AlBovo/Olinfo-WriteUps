#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int N, k; fin >> N;
    int vittorie[N];
    fill(vittorie, vittorie+N, 0);
    k = (N*(N-1))/2;
    for(int i=0; i<k; i++){
        int s1, s2, g1, g2; fin >> s1 >> s2 >> g1 >> g2;
        if(g1 > g2){
            vittorie[s1-1] += 3;
        } 
        else if(g2 > g1){
            vittorie[s2-1] += 3;
        } 
        else if(g2 == g1){   
            vittorie[s1-1]++;
            vittorie[s2-1]++;
        } 
    }
    int pos = -1, maxi = -1; 
    for(int i=0; i<N; i++){
        if(vittorie[i] > maxi) pos = i; maxi = max(maxi, vittorie[i]);
    }
    fout << pos+1 << " " << maxi;
    return 0;
}