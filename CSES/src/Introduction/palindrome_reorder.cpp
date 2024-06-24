#include<bits/stdc++.h>
using namespace std;
 
int main(){
    char c;
    map<char, int> m;
    while((c = getchar()) != '\n'){
        if(m.count(c))
            m[c]++;
        else
            m[c] = 1;
    }
    c = 0;
    string a = "";
    for(auto &i : m){
        if(i.second % 2 != 0){
            if(c != 0){
                cout << "NO SOLUTION";
                return 0;
            }
            c = i.first;
        }
        a += string((i.second >> 1), i.first);
    }
    cout << a;
    reverse(a.begin(), a.end());
    if(c != 0)
        cout << c;
    cout << a;
    return 0;
}