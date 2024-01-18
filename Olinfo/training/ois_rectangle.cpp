// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    vector<long long>v(n);
    for(auto &i:v) cin >> i;
    sort(v.begin(), v.end(), greater<long long>());
    long long f = 0, r = 0;
    for(int i=0; i<n-1; i++){
        if(v[i] == v[i+1] && f == 0) f = v[i++];
        else if(v[i] == v[i+1] && r == 0) r = v[i++];
        if(r != 0 && f != 0){
            cout << f * r;
            return 0;
        }
    }
    cout << f * r;
    return 0;
}