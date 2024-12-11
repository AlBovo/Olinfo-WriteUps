// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        int n, t = 0; cin >> n;
        vector<int>v;
        for(int e=0; e<n; e++){
            char c; cin >> c;
            if(t > 0 && c == '-'){
                v.push_back(t);
                t = 0;
            }
            else if(c == '.')
                t++;
        }
        if(t > 0)
            v.push_back(t);
        sort(v.begin(), v.end(), greater<int>());
        int maxi = 0;
        for(int e : v){
            maxi = max({maxi - 2, e - 1, 0});
        }
        cout << v.size() << " " << ceil(maxi / 2.0) + v.size() << "\n";
    }
    return 0;
}