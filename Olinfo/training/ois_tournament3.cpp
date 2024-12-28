// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    queue<pair<int, int>>s;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        s.push({a, i});
    }
    while(n > 2){
        for(int i=0; i<n/2; i++){
            auto p1 = s.front();
            s.pop();
            auto p2 = s.front();
            s.pop();
            s.push((p1.first > p2.first ? p1 : p2));
        }
        n /= 2;
    }
    auto p1 = s.front();
    s.pop();
    auto p2 = s.front();
    s.pop();
    if(p1.first > p2.first)
        cout << p1.second << " " << p2.second;
    else
        cout << p2.second << " " << p1.second;
    return 0;
}