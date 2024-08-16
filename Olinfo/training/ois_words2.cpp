// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main(){
    long long tot = 0, tot2 = 1;
    string s; cin >> s;
    for(int i=s.length()-1; i>=0; i--){
        tot = (tot + ((s[i] - 'a' + 1) * tot2) % mod) % mod;
        tot2 = (tot2 * 26) % mod; 
        // cout << (tot + mod - 1) % mod << "\n";
    }
    cout << (tot + mod - 1) % mod;
}