#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, maxn = 0, maxt = 0; fin >> n;
    int sus[101];
    for(int i=0; i<101; i++){
        sus[i] = 0;
    }
    for(int i=0; i<n; i++){
        int temp, temp1; fin >> temp >> temp1;
        if(sus[temp] != 0){
            sus[temp] += temp1;
        }
        else{
            sus[temp] = temp1;
        }
    }
    for(int i=0; i<101; i++){
        if(sus[i] != 0 && sus[i] > maxn){
            maxn = sus[i];
            maxt = i;
        }
    }

    fout << maxt << " " << maxn;
    return 0;
}