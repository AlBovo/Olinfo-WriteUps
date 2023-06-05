#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int i=0; i<t; i++){
        int n, k, tot = 0; fin >> n >> k;
        bool fatto = false;
        priority_queue<int>pq;
        for(int e=0; e<n; e++){
            int f; fin >> f;
            if(i == 2){
                cout << f << " " << k << " " << ((!pq.empty())? to_string(pq.top()) : "vuoto") << "\n";
            }
            if(!fatto){
                --k;
                pq.push(f);
                if(k == 0){
                    k += pq.top();
                    pq.pop();
                    tot++;
                }

                if(k < 0){
                    fout << "Case #" << i+1 << ": " << -1 << "\n";
                    fatto = true;
                }
            }
        }
        if(!fatto){
            fout << "Case #" << i+1 << ": " << tot << "\n";
        }
    }
    return 0;
}