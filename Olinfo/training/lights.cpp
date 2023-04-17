// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, m; fin >> n >> m;
    unordered_map<int, int>ma;
    vector<int>v(n);
    for(int &i:v){
        fin >> i;
    }
    int pos = 0, last = v[0], mini = (int)10e8;
    for(int i=0; i<n; i++){
        ma[v[i]]++;
        if(ma[last] > 1){
            while(ma[last] > 1){
                pos++;
                ma[last]--;
                if(ma[last] == 0){
                    ma.erase(last);
                }
                last = v[pos];
            }
        }
        if(ma.size() == m){
            mini = min(i-pos, mini);
        }
    }
    cout << mini+1;
    return 0;
}

