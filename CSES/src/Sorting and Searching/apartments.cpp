#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    int p1 = 0, p2 = 0, t = 0;
    while(p1 < n && p2 < m){
        if(abs(a[p1] - b[p2]) <= k){
            p1++;
            p2++;
            t++;
        }
        else{
            if(a[p1] > b[p2])
                p2++;
            else if(a[p1] < b[p2])
                p1++;
            else{
                if(n - p1 > m - p2)
                    p1++;
                else
                    p2++;
            }
        }
    }
    cout << t;
    return 0;
}