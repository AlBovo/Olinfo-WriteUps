// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n, m; cin >> n >> m;
    long long sum = 0;
    vector<long long> v(n);
    for(long long &i:v){
        cin >> i;
        sum += i;
    }
    if(sum < m*n){
        cout << 1;
    }
    else{
        sort(v.begin(), v.end(), greater<long long>());
        long long ans = 0, pos = 0;
        while(sum > m*n){
            sum -= v[pos++] - 1;
            ans++;
        }
        cout << ans;
    }
}