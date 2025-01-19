// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c; cin >> a >> b >> c;
    int a1, b1, c1; cin >> a1 >> b1 >> c1;
    cout << abs(a - a1) + abs(b - b1) + abs(c - c1);
    return 0;
}