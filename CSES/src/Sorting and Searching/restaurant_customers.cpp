#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<pair<int, bool>>v(n * 2); // {time : is_out}
    bool f = false;
    for(auto &i : v){
        cin >> i.first;
        i.second = f;
        f = !f;
    }
    sort(v.begin(), v.end());
    int tot = 0, m = 0;
    for(auto &i : v){
        tot = (i.second)? tot - 1 : tot + 1;
        m = max(tot, m);
    }
    cout << m;
    return 0;
}