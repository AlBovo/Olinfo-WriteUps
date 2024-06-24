#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x; cin >> n >> x;
    vector<int> p(n);
    for(int &i : p) cin >> i;
    sort(p.begin(), p.end());
 
    int p1 = 0, p2 = n-1, t = 0;
    while(p1 < p2){
        if(p[p1] + p[p2] > x){
            t++;
            p2--;
        }
        else{
            t++;
            p1++;
            p2--;
        }
    }
    if(p1 == p2){
        t++;
    }
    cout << t;
    return 0;
}