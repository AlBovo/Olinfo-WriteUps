// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int>vv(n);
    for(int &i : vv) cin >> i;
    int maxi = 0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a <= m && vv[i] % 2 == 0) maxi = max(maxi, vv[i]);
    }
    cout << maxi;
    return 0;
}