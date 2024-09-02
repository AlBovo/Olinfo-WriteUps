#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int e=0; e<t; e++){
        int n, tot = 0; fin >> n;
        vector<int>v(n), r;
        for(int &i:v) fin >> i;
        int c = 1;
        while(c * 2 <= n){
            r.push_back(v[c-1]);
            if(n % c != 0){
                c++;
                continue;
            }
            bool done = false;
            for(int i=c; i<n; i++){
                if(v[i] != r[i % c]){
                    done = true;
                    break;
                }
            }
            if(!done){
                tot = n / c;
                break;
            }
            c++;
        }

        fout << "Case #" << e+1 << ": " << (tot == 0? 1: tot) << "\n";
    }
    return 0;
}