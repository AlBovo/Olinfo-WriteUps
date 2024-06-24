#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    if(n == 1){
        cout << "1";
        return 0;
    }
    if(n <= 3){
        cout << "NO SOLUTION";
    }
    else if(n == 4){
        cout << "2 4 1 3";
    }
    else{
        int c = 1;
        while(c <= n){
            cout << c << " ";
            c += 2;
        }
        c = 2;
        while(c <= n){
            cout << c << " ";
            c += 2;
        }
    }
 
    return 0;
}