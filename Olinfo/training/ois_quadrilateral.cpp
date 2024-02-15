// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long>v(n);
    for(long long &i:v) cin >> i;
    sort(v.begin(), v.end());
    for(long long i=3; i<n; i++){
        if(v[i-3] + v[i-2] + v[i-1] > v[i]){
            cout << v[i-3] << " " << v[i-2] << " " << v[i-1] << " " << v[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}