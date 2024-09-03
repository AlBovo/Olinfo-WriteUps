// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    vector<string>v(n), m(10);
    for(auto &i : v) fin >> i;
    for(auto &i : m) fin >> i;

    for(int i=0; i<n; i++){
        string res = "";
        for(int e=0; e<v[i].length();){
            for(int j=0; j<10; j++){
                if(v[i].length() - e < m[j].length())
                    continue;

                if(v[i].substr(e, m[j].length()) == m[j]){
                    res += (char)(j + '0');
                    e += m[j].length();
                }
            }
        }
        fout << res << "\n";
    }
    return 0;
}