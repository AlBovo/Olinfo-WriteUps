// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    int tot = 0, ctot = 0, r = 0;
    for(int i=0; i<n; i++){
        if(a[i] - b[i] > c[i]){
            tot += a[i] - b[i];
            ctot -= b[i];
        }
        else{
            tot += c[i];
            ctot += c[i];
        }
        
        if(ctot < 0){
            r += ctot * -1;
            ctot = 0;
        }
    }
    cout << tot << " " << r;
    return 0;
}