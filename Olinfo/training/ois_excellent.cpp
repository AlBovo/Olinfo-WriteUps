// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    if(n < 2){
        cout << -1;
    }
    else if(n == 2){
        cout << 15;
    }
    else{
        long long mod = 0;
        for(int i=0; i<n-3; i++){
            cout << 1;
        }
        switch((n-3) % 3){
            case 0:
                cout << 111;
                break;
            case 1:
                cout << 551;
                break;
            case 2:
                cout << 151;
                break;
            
        }
    }
}