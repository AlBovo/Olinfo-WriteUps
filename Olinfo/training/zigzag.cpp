// Punti: 40.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<int>v(n);
    for(auto &x : v){
        fin >> x;
    }
    bool t;
    int pos = 0;
    for(int e=0; e<v.size()-1; e++){
        if(e == 0){
            while(v[e] == v[e+1] && e<v.size()){
                e++;
            }
            if(e == v.size()){
                fout<<0;
                return 0;
            }
            t = v[e] > v[e+1];
        }
        else{
            if(t != v[e]>v[e+1]){
                n -= pos;
                pos = 0;
                t = !t;
            }
            else if(t == v[e]>v[e+1]){
                pos++;
            }
        }
    }
    fout << n;
    cout << n;
    return 0;
}
