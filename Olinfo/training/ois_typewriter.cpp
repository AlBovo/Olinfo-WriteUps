// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin ("input.txt");
    string a,b,c;
    fin >> a >> b >>c;
    long long i1 = 0, i2 = 0, i3 = 0;
    
    string res = "";
    while(i1 < a.length()){
        char h = a[i1];
        long long b1 = 0, b2 = 0, b3 = 0;
        for(long long i = i1; i < a.length()+1; i++){
            if(i == a.length() || a[i] != h){ b1 = i-i1; i1 = i; break;}
        }
        for(long long i = i2; i < b.length()+1; i++){
            if(b[i] != h && i == i2){ cout << "IMPOSSIBLE"; return 0; }
            if(i == b.length() || b[i] != h){ b2 = i-i2; i2 = i; break; }
        }
        for(long long i = i3; i < c.length()+1; i++){
            if(c[i] != h && i == i3){ cout << "IMPOSSIBLE"; return 0; }
            if(i == c.length() || c[i] != h){ b3 = i-i3; i3 = i; break; }
        }
        // cout << b1 << " " << b2 << " " << b3 << "\n";
        long double media = b1+b2+b3 - max({b1, b2, b3}) - min({b1, b2, b3});
        
        for(long long i = 0; i < media; i++) res += h;
    }
    
    cout << res;
    return 0;
}