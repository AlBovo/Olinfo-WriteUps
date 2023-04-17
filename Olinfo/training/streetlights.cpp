// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n, m, k; cin >> n >> m >> k;
    vector<long long>v(n);
    for(long long &i:v){
        cin >> i;
    }
    long long tot = 0, sum = 0;
    for(long long i=0; i<=n-m; i++){
        if(i != 0){
            sum -= v[i-1];
            sum += v[i+m-1];
        }
        if(!i){
            for(int e=0; e<m; e++){
                sum += v[i+e];
            }
        }
        if(sum < k){
            for(long long e=m-1; e>=0; e--){
                if(sum == k){ break; }
                if(v[i+e] == 0){
                    v[i+e] = 1;
                    ++tot;
                    ++sum;
                }
            }
        }
    }
    cout << tot;
    return 0;
}