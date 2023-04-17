// Punti: 70.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    int n, m, tot = 0; fin >> n >> m;
    vector<int>v(n, -1), ma(n, -1);
    for(int i=0; i<m; i++){
        char s; int t; fin >> s >> t;
        if(s == 'b'){
            for(int e=0; e<n; e++){
                if(e == t){
                    if(v[t] != -1){
                        int pos = t;
                        do{
                            int temp = v[pos];
                            ma[pos] = pos;
                            v[pos] = pos;
                            //cout << pos << " " << temp << "\n";
                            pos = temp;
                            tot++;
                        }while(v[pos] != -1);
                        v[pos] = pos;
                        ma[pos] = pos;
                    }
                    else{
                        v[e] = t;
                        ma[t] = t;
                    }
                    break;
                }
                else if(v[e] == -1){
                    ma[t] = e;
                    v[e] = t;
                    break;
                }
            }
        }
        else{
            v[ma[t]] = -1;
        }
        #ifndef EVAL
        for(int i:v){
            cout << i << " ";
        }
        cout << "\n";
        #endif
    }
    cout << tot;
    return 0;
}