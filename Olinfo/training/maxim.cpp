// Punti: 50.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    long long n, k, maxi = 0; fin >> n >> k;
    priority_queue<long long>pq;
    vector<long long>q(300001, 0), v(n);
    for(long long &i:v){
        fin >> i;
    }
    // prima parte
    for(long long i=0; i<k; i++){
        pq.push(v[i]);
    }
    for(long long i=0; i<=k && i<n; i++){
        pq.push(v[i+k]);
        maxi = max(maxi, abs(pq.top()-v[i]));
    }
    // seconda parte
    for(long long i=k+1; i<n-k; i++){
        if(i-k-1>=0){
            q[v[i-k-1]]++;
        }
        pq.push(v[i+k]);
        while(q[pq.top()] > 0){
            q[pq.top()]--;
            pq.pop();
        }
        maxi = max(maxi, abs(pq.top()-v[i]));
    }
    // terza parte
    for(long long i=n-k; i<n; i++){
        if(i-k-1>=0){
            q[v[i-k-1]]++;
        }
        while(q[pq.top()] > 0){
            q[pq.top()]--;
            pq.pop();
        }
        maxi = max(maxi, abs(pq.top()-v[i]));
    }
    #ifndef EVAL
    cout << (pq.size() == k+1) << " " << pq.size() << "\n";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
    #endif
    cout << maxi;
    return 0;
}