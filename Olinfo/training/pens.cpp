// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n; fin >> n;
    vector<long long>v(n);
    for(long long &x:v){
        fin >> x;
    }

    for(int i=0; i<v.size(); i++){
        if(!i && v[i] > 1){
            if(v[i+1] == 0){
                v[i+1]++;
                v[i]--;
            }
        }
        else if(i == v.size()-1 && v[i] > 1){
            if(v[i-1] == 0){
                v[i-1]++;
                v[i]--;
            }
        }
        else if(v[i] > 1){
            if(v[i-1] == 0){
                v[i-1]++;
                v[i]--;
            }
            if(v[i+1] == 0 && v[i] > 1){
                v[i+1]++;
                v[i]--;
            }
        }
    }
    long long maxi = 0;
    for(long long i:v){
        if(!i) maxi++;
    }
    cout << maxi;
    return 0;
}
