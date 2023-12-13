// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        // cout << (int)ceil((double)(a - 33) / 10) << " " << b / 11 << "\n";
        if(b > 52 || a > 53 || a < 33 || (int)ceil((double)(a - 33) / 10) > b / 11){
            cout << "-1 -1\n";
            continue;
        }

        a -= 33;
        int c = 0;
        while(b >= 11 && c < 2){
            if(a >= 10){
                cout << "10 ";
                a -= 10;
            }
            else{
                cout << a << " ";
                a = 0;
            }
            cout << "11\n";
            b -= 11; c++;
        }

        for(int e=0; e<3; e++){
            cout << "11 ";
            if(b >= 10){
                cout << 10 << "\n";
                b -= 10;
            }
            else{
                cout << b << "\n";
                b = 0;
            }
        }

        assert(a == 0 && b == 0);
    }
    return 0;
}