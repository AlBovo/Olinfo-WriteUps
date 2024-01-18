// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int>v(n);
    for(int &i: v){
        cin >> i;
    }
    priority_queue<pair<int, int>>pq;
    for(int i=0; i<m; i++) pq.push({v[i], i});
    auto swap = pq.top(); int mini; pq.pop();
    mini = abs(swap.first - pq.top().first);
    pq.push(swap);

    for(int i=m; i < n; i++){
        pq.push({v[i], i});
        while(pq.top().second <= i-m) pq.pop();
        swap = pq.top(); pq.pop();
        while(pq.top().second <= i-m) pq.pop();
        mini = min(mini, abs(swap.first - pq.top().first));
        pq.push(swap);
    }

    cout << mini / 2;
    return 0;
}