// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    vector<long long>v(n);
    vector<short>tieni(n, 0);
    for(long long &i : v) cin >> i;
    tieni[0] = tieni[n-1] = 0;
    long long last = 0;
    for(long long i=1; i<n; i++){
        if(v[i] < v[last]){
            tieni[i]++;
        }
        else{
            last = i;
        }
    }
    last = n-1;
    for(long long i=n-2; i>=0; i--){
        if(v[i] < v[last]){
            tieni[i]++;
        }
        else{
            last = i;
        }
    }
    long long tot = 0;
    last = 0;
    for(long long i=1; i<n; i++){
        if(tieni[i] < 2){
            tot += (i - last) * min(v[i], v[last]);
            last = i;
        }
    }
    cout << tot;
    return 0;
}