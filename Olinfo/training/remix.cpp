// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){ // PaH TuNZ
    int n, i = 0; fin >> n;
    string s; fin >> s;
    while(true){
        if(i <= s.size()-3 && s[i] == 'P'){
            //cout << s << "\n";
            if(s.substr(i, 3) == "PaH"){
                s.replace(s.begin()+i, s.begin()+i+3, " ");
                i -= 3;
            }
        }
        else if(i <= s.size()-4 && s[i] == 'T'){
            //cout << s << "\n";
            if(s.substr(i, 4) == "TuNZ"){
                s.replace(s.begin()+i, s.begin()+i+4, " ");
                i -= 4;
            }
        }
        else if(i == s.size()){
            break;
        }
        i++;
    }
    int t = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            t++;
        }
        else{
            break;
        }
    }
    s.erase(s.begin(), s.begin()+t);
    fout << s;
    return 0;
}