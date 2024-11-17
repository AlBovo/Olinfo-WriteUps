// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    for(int i=1; ; i++){
        long long c = pow(i, 2);
        if(c > n){
            cout << i-1;
            return 0;
        }
        n -= c;
    }
    return 0;
}