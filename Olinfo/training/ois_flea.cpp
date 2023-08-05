// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n, tot = 0; cin >> n;
    for(int i=0; i<n; i++){
        char s; cin >> s;
        if(s == 'L'){
            tot--;
        }
        else{
            tot++;
        }
    }
    cout << ((tot < 0)? tot*-1 : tot);
    return 0;
}