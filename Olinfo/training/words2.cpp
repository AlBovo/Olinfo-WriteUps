// Punti: 0.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    string s; fin >> s;
    long long t = 0;
    for(int i=0; i<s.size(); i++){
        t += ((s[i]-'a'+1)*(long long)pow(26, i))%(long long)1000000007;
        t %= (long long)1000000007;
    }
    fout << t-1;
    return 0;
}
