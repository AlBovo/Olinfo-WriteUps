// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, tot = 0; cin >> n;
    vector<char>v(n);
    for(auto &i : v) cin >> i;

    bool doing = false;
    for(int i=0; i<n; i++){
        if(v[i] == 'I' || v[i] == 'N'){
            if(!doing){
                doing = true;
                tot++;
            }

            v[i] += 32;
        }
        else{
            doing = false;
        }
    }

    doing = false;
    for(int i=0; i<n; i++){
        if(v[i] == 'i'){
            if(!doing){
                doing = true;
                tot++;
            }
        }
        else{
            doing = false;
        }
    }

    cout << tot;
    return 0;
}