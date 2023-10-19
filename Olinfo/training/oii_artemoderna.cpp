// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
bool ordina(int N, vector<int> V, vector<int> &L){
    int last, pos, st;
    for(int i=0; i<N; ){
        if(i == 0) pos = V[0];
        st = i;
        while(i < N){
            if(pos > V[i] && st != 0) return false;
            else if(i == st){
                last = V[i];
                i++;
            }
            else if(V[i] <= last){
                last = V[i];
                i++;
            }
            else{
                break;
            }
        }
        last = V[st];
        pos = V[st];
        L.push_back(i-st);
    }
    return true;
}
#ifndef EVAL
int main() {
    int n; cin >> n;
    vector<int> v(n), l;
    for(int &i:v) cin >> i;
    if(ordina(n, v, l)){
        cout << "YES\n";
        cout << l.size() << '\n';
        for(int i:l) cout << i << ' ';
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
#endif