// Punti: 30.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<int>v(n);
    vector<bool>ve(n, false);
    for(int &i:v){
        fin >> i;
        ve[i] = true;
    }
    int maxi = 0;
    for(int i=0; i<n; i++){
        if(ve[i]){
            int t = 1, p = i, f = i;
            unordered_set<int>s;
            s.insert(p);
            while(!s.count(v[p])){
                p = v[p];
                s.insert(p);
                t++;
            }
            p = v[p];
            if(p == f){
                maxi = max(maxi, t);
            }
        }
    }
    cout << maxi;
    return 0;
}