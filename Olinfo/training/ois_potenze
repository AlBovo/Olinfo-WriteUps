// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, maxi = 1; fin >> n;
    for(long long i=n; i>1; i--){
        if(((int)((float)log(n)/(float)log(i))) > 1){
            maxi = max((long long)pow(i,(long long)((float)log(n)/(float)log(i))), maxi);
        }
    }
    fout << maxi;
    return 0;
}