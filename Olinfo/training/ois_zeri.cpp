// Punti: 80.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    string s, c = "1"; fin >> s;
    int l = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'x'){
            //cout << x << " " << stoi(s.substr(l, abs(l-i))) << "\n";
            c = to_string(((stoull(c)%(unsigned long long)(10e9))*(stoull(s.substr(l, abs(l-i)))%(unsigned long long)(10e9)))%(unsigned long long)(10e9));
            l = i+1;
            /*
            if(x*stoi(s.substr(l, abs(l-i))) >= (unsigned long long)(10e9+7)){
                x = (x*stoi(s.substr(l, abs(l-i))))%(unsigned long long)(10e12);
            }
            else{
                x = (x*stoi(s.substr(l, abs(l-i))));
            }
            */
        }
    }
    if(l < s.size()){
        //cout << x << " " << stoi(s.substr(l, s.size()-1)) << "\n";
        c = to_string(((stoull(c)%(unsigned long long)(10e9))*(stoull(s.substr(l, s.size()))%(unsigned long long)(10e9)))%(unsigned long long)(10e9));
        /*
        if(x*stoi(s.substr(l, s.size()-1)) >= (unsigned long long)(10e9+7)){
            x = (x*stoi(s.substr(l, s.size()-1)))%(unsigned long long)(10e12);
        }
        else{
            x = (x*stoi(s.substr(l, s.size()-1)));
        }
        */
    }
    s = c;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] != '0'){
            fout << abs((long long)s.size()-1-i);
            return 0;
        }
        l++;
    }
    fout << s.size();
    return 0;
}