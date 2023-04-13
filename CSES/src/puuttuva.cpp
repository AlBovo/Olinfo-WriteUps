#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n; cin >> n;
    vector<long long>v(n-1);
    for(auto &x : v){
        cin >> x;
    }
    sort(v.begin(), v.end());
    if(v[0] != 1){
        cout << 1;
        return 0;
    }
    if(v[v.size()-1] != n){
        cout << n;
        return 0;
    }
    for(int i=0; i<v.size()-1; i++){
        if(v[i]+1 != v[i+1]){
            cout << v[i]+1;
            return 0;
        }
    }
    return 0;
}