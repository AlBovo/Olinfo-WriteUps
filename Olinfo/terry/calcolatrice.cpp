#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        long long n, curr; cin >> n;
        long long tot = 0;

        if(n == 1){
            tot = 1;
        }
        else{
            curr = n;
            while(curr != 1){
                if(curr % 2 == 0)
                    curr /= 2LL;
                else
                    curr++;
                tot++;
            }
        }

        cout << "Case #" << i+1 << ": " << tot << "\n";
    }
    return 0;
}