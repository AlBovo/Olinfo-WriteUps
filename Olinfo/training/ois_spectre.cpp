#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int N, tot = 0; fin >> N;
    map<string, int> m;
    for(int i=0; i<N; i++){
        string var1, var2, var3, temp;
        fin >> var1 >> temp >> var2 >> temp >> var3;
        if(m.count(var2) == 0 && m.count(var3) == 0){
            tot += 1;
        }
        m[var1] = 1;
    }
    cout << tot;
    return 0;
}