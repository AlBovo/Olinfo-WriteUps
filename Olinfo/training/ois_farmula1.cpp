// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int f[] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    for(int i=0; i<n; i++){
        int c, tot = 0, r = 0; cin >> c;
        for(int e=0; e<c; e++){
            int t; cin >> t;
            if(t == 1) r++;
            if(t <= 10) tot += f[t];
        }
        if(tot >= r * 18 + (c-r) * 25) cout << "Champion\n";
        else cout << "Practice harder\n";
    }
    return 0;
}