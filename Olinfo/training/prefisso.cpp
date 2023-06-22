// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, tot = 0; fin >> n;
    vector<string>v(n);
    for(auto &x : v){
        fin >> x;
    }
    int temp = 1;
    bool s = true;
    for(int i=0; i<v[0].size(); i++){
        string t = v[0].substr(0, temp);
        for(int e=1; e<v.size(); e++){
            if(v[e].substr(0, temp) != t){
                s = false;
                break;
            }
        }
        if(!s){
            fout << tot;
            return 0;
        }
        tot++;
        temp++;
    }
    return 0;
}