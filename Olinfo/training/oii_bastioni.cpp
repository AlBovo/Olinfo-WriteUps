// Punti: 77.0
#include<bits/stdc++.h>
using namespace std;

int arrampicate(int N, string S){
    int tot = 0; char curr;
    S += "=";
    for(int i=0; i<=N;){
        curr = S[i++];
        if(curr != '#' && curr != '?'){
            while(i <= N && S[i] != '#' && S[i] != '?' && S[i] == curr || S[i] == '=' || curr == '='){
                if(curr == '=') curr = S[i];
                i++;
            }
            if(curr != '#' && curr != '?')
                i++;
        }
        tot++;
    }
    return tot;
}

#ifndef EVAL
int main(){
    int n; cin >> n;
    string s; cin >> s;
    cout << arrampicate(n, s);
    return 0;
}
#endif