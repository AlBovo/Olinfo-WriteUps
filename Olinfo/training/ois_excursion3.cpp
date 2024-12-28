// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> c >> b;
    int tot1 = 0, tot2 = 0;
    
    if(a <= b){
        b -= a;
        tot1 += 3*a + 2*b + 3*c;
        tot2 += 2*a + b + c;
    }
    else{
        c -= (a-b);
        tot1 += 3*b + 4*(a-b) + 3*c;
        tot2 += 2*b + 2*(a-b) + c;  
    }
    cout << tot1 << "\n" << tot2;
    return 0;
}