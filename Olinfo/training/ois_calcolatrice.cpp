// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    unordered_map<char, char> c = {
        {'0', '0'}, {'1', '1'},
        {'2', '2'}, {'5', '5'},
        {'6', '9'}, {'8', '8'},
        {'9', '6'}
    };
    int n; fin >> n;
    string s = to_string(n), s1 = "";
    for(int i=0; i<s.length(); i++){
        if(!c.count(s[i])){
            fout << n;
            return 0;
        }
        s1 = c[s[i]] + s1;
    }
    if(s1[0] == '0')
        fout << s;
    else
        fout << min(n, stoi(s1));
    return 0;
}