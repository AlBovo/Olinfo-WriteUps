#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    if(n % 4 == 0 || (n + 1) % 4 == 0){
        cout << "YES\n";
        if(n % 4 == 0){
            cout << (n >> 1) << "\n";
            for(int i=0; i<(n >> 2); i++){
                cout << i + 1 << " " << n - i << " "; 
            }
            cout << "\n" << (n >> 1) << "\n";
            for(int i=(n >> 2); i<(n >> 1); i++){
                cout << i + 1 << " " << n - i << " ";
            }
        }
        else{
            cout << (n >> 1) + 1 << "\n";
            cout << "1 2 ";
            for(int i=4; i<n; i++){
                cout << i << " ";
                i += 3;
                cout << i << " ";
            }
            cout << "\n" << (n >> 1) << "\n";
            cout << "3 ";
            for(int i=5; i<n; i+=3){
                cout << i << " " << ++i << " ";
            }
        }
    }
    else{
        cout << "NO\n";
    }
    return 0;
}