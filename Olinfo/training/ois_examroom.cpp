#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main(){
    long r, c, k, maxStud, fitR, fitC; fin >> r >> c >> k;    
    fitR = c/k;
    fitC = r/k;
    if(c % k > 0){
        fitR++;
    }
    if(r % k > 0){
        fitC++;
    }
    fout << fitC*fitR;
    return 0;
}