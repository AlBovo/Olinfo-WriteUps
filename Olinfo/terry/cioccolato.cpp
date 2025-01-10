#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        long long n, m, k;
        cin >> n >> m >> k;
        while(k > 0){
            int diff;
            if(n < m){
                diff = m - n;
                if(diff > k){
                    m -= k;
                    break;
                }
                else
                    k -= diff;
                m -= m - n;
            }                
            else if(n > m){
                diff = n - m;
                if(diff > k){
                    n -= k;
                    break;
                }
                else
                    k -= diff;
                n -= diff;
            }
            else{
                if(k % 2 == 0){
                    n -= k/2;
                    m -= k/2;
                }
                else{
                    n -= k/2;
                    m -= k - (k / 2);
                }
                break;
            }
        }
        cout << "Case #" << i+1 << ": " << (long long)n*m << "\n";
    }
    return 0;
}