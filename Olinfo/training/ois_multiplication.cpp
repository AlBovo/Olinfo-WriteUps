// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    for(int i=0; i<n; i++){
        int s; fin >> s;
        set<long long>se;
        for(int e=1; true; e++){
            string st = to_string(e*s);
            for(char c : st){
                se.insert(c - '0');
            }
            if(se.size() == 10){
                fout << e << "\n";
                break;
            }
        }
    }
    return 0;
}
