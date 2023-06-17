// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, maxi = -1; fin >> n;
    for(int i=0; i<n; i++){
        int a, b; fin >> a >> b;
        if((a+b)% 2 == 0){
            maxi = max(maxi, a+b);
        }
    }
    fout << maxi;
    return 0;
}