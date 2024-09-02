#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long t; fin >> t;
    for(long long e=0; e<t; e++){
        long long n, tot = 0; fin >> n;
        
        vector<int>a(n), b(n);
        for(int &i:a) fin >> i;
        for(int &i:b) fin >> i;
        int p = 0;
        for(int i=0; i<n; i++){
            while(p < n && b[p] < a[i])
                p++;
            
            if(b[p] == a[i]){
                tot++;
                p++;
            }
        }

        fout << "Case #" << e+1 << ": " << tot << "\n";
    }
    return 0;
}