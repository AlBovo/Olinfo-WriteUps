#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n; cin >> n;
    for(long long i=0; i<n; i++){
        long long x, y; cin >> x >> y;
        if(x == 1 && y == 1){
            cout << 1 << "\n";
            continue;
        }
        if(x > y){
            long long x1 = x;
            if(x % 2 != 0)
                x1--;
            x1 *= x1;
            if(x % 2 != 0)
                x1++;
            x1 += (x % 2 == 0)? 1 - y : y - 1;
            cout << x1 << "\n";
        }
        else if(y > x){
            long long y1 = y;
            if(y % 2 == 0)
                y1--;
            y1 *= y1;
            if(y % 2 == 0)
                y1++;
            y1 += (y % 2 == 0)? x - 1 : 1 - x;
            cout << y1 << "\n";
        }
        else{
            cout << x * x - x + 1 << "\n";
        }
    }
    return 0;
}