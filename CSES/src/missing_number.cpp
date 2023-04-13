#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int>v(n);
    for(int &x:v){
        cin >> x;
    }
    sort(v.begin(), v.end());
    if(v[0] > 1){
        cout << 1;
        return 0;
    }
    if(v[n-1] < n){
        cout << n;
        return 0;
    }
    for(int i=0; i<v.size()-1; i++){
        if(v[i] == v[i+1]-2){
            cout << v[i]+1;
            return 0;
        }
    }
    return 0;
}