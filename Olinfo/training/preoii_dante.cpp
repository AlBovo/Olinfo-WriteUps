// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int rimembra(int N, int K, vector<int> V){
    int k = K, last = 0, tot = 0, maxi = 0;
    for(int i=0; i<N && last<N; i++){
        if(V[i] == 0){
            if(K == 0)
                tot = 0;
            else if(k > 0){
                V[i] = 2;
                tot++;
                k--;
            }
            else{
                while(last < N-1 && V[last] != 2){
                    last++;
                    tot--;
                }
                V[last] = 0;
                last++;
                V[i] = 2;
            }
        }
        else
            tot++;
        maxi = max(maxi, tot);
    }
    return maxi;
}
#ifndef EVAL
int main(){
    int n, k; cin >> n >> k;
    vector<int>v(n);
    for(int &i : v)
        cin >> i;
    cout << rimembra(n, k, v);
}
#endif