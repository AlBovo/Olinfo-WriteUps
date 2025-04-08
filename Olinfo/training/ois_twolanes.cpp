// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string su, sd; cin >> su >> sd;
    for(int i=0; i<n; i++){
        if(su[i] == 'R' && sd[i] == 'R'){
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}