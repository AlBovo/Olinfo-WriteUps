// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        long long n, k; cin >> n >> k;
        if(k == 1){
            cout << "YES\n";
            continue;
        }
        if(k*(k+1)/2 == n || k*(k+1)/2+1 == n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}