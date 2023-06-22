// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<int>v(n);
    for(auto &x:v){
        fin >> x;
    }
    int x, y;
    for(int i=0; i<n; i++){
        if(v[i] < 6){
            x = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(v[i] >= 6){
            y = i;
            break;
        }
    }

    if(x >= y){
        fout << -1;
    }
    else{
        fout << y-x+1;
    }
    return 0;
}