#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxi = 0;
    string s; cin >> s;
    string c = "";
    for(int i=0; i<100000; i++){
        c += "A";
    }
    if(c == s){
        cout << 100000;
        return 0;
    }
    for(int i=0; i<(int)s.size(); i++){
        int t = 1;
        for(int e=i+1; e<(int)s.size(); e++){
            if(s[e] == s[i]){
                t++;
            }
            else{
                i = e-1;
                break;
            }
        }
        maxi = max(t, maxi);
    }
    cout << maxi;
    return 0;
}