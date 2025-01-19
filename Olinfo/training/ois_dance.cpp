// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, d; cin >> n >> d;
    vector<int>a(n);
    for(int &i : a) cin >> i;
    for(int i=0; i<n; i++){
        int b; cin >> b;
        if(b - a[i] > d){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}