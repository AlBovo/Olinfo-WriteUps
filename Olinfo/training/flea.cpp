// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n, tot = 0; fin >> n;
    for(int i=0; i<n; i++){
        char s; fin >> s;
        if(s == 'L'){
            tot--;
        }
        else{
            tot++;
        }
    }
    fout << abs(tot);
    return 0;
}