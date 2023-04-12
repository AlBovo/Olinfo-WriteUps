#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, somma, a, b = 0; fin >> n >> a >> b;
    somma = a-b;
    for(int i=1; i<n; i++){
        fin >> a;
        if(b-a > somma){
            somma = b-a;
        }
        if(a-b > somma){
            somma = a-b;
        }
        fin >> b;
        if(a-b > somma){
            somma = a-b;
        }
    }
    fout << somma;
    return 0;
}