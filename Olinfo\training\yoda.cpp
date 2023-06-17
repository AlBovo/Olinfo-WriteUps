// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    string str, s = "";
    getline(fin, str);
    vector<string>st;
    for (auto x : str){
        if (x == ' '){
            st.push_back(s);
            s = "";
        }
        else {
            s += x;
        }
    }
    st.push_back(s);
    for(int i=st.size()-1; i>=0; i--){
        fout << st[i] << " ";
    }
    return 0;
}