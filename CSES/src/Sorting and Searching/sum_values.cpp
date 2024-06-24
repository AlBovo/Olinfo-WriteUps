#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x; cin >> n >> x;
    unordered_map<int, int>m;
    for(int i=0; i<n; i++){
        int c; cin >> c;
        if(c > x)
            continue;
        if(m.count(x - c)){
            cout << m[x-c] + 1 << " " << i + 1;
            return 0;
        }
        m[c] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}