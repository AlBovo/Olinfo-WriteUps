#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    unordered_map<int, bool>m;
    vector<int> v;
    string s; fin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'h' && s.substr(i, 5) == "hello"){
            m[i] = 1;
        }
        else if(s[i] == 'w' && s.substr(i,5) == "world"){
            m[i] = 0;
            v.push_back(i);
        }
    }
    long long tot = 0;
    for(auto i : m){
        if(i.second){
            auto it = upper_bound(v.begin(), v.end(), i.first) - v.begin();
            tot += v.size() - it;
        }
    }
    cout << tot;
    return 0;
}