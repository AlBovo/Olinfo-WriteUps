// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    if(n > m){
        cout << -1;
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int e=0; e<i; e++)
            cout << '#';
        for(int e=i; e<m; e++)
            cout << '.';
        cout << '\n';
    }
    return 0;
}