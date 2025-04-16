// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<bool> a(n - 1, true);
    int t = 0;
    for(int i=2; i<=n; i++){
        bool c = false;
        for(int e=i; e<=n; e+=i){
            c |= a[e-2];
            a[e-2] = false;
        }
        if(c) t++;
    }
    cout << t;
    return 0;
}
