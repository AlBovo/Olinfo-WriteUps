// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>v(n);
    for(int &i:v) cin >> i;
    int pos = 0;
    for(int i=1; i<n; i++){
        if(v[pos] > v[i]) pos = i;
    }
    for(int i=1; i<n; i++){
        if(pos + i == n){ // stretto
            if(v[0] < v[n-1]){
                cout << -1;
                return 0;
            }
        }
        else if(v[(pos + i) % n] < v[(pos + i-1) % n]){
            cout << -1;
            return 0;
        }
    }
    if(pos == 0)
        cout << 0;
    else
        cout << n - pos;
    return 0;
}