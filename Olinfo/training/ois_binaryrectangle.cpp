// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

bool fun(){
    int n, m, e=0; cin >> n >> m;
    pair<int, int> tl, tr;
    tl = tr = {-1, -1};
    vector<string>s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    for(; e<n; e++){
        for(int j=0; j<m; j++){
            char a = s[e][j];
            if(a == '1'){
                if(tl != make_pair(-1, -1)){
                    return false;
                }
                tl = tr = {e, j};
                while(j+1<m && a == '1'){
                    a = s[e][++j];
                    if(a == '1'){
                        tr = {e, j};
                    }
                }
            }
        }
        if(tl != make_pair(-1, -1))
            break;
    }
    bool fin = false;
    for(e = e+1; e<n; e++){
        bool one = false, rotto = false;
        for(int j=0; j<m; j++){
            char a = s[e][j];
            one |= a == '1';
            if(a == '1' && (j < tl.second || j > tr.second))
                return false;
            if(a == '0' && (j >= tl.second && j <= tr.second))
                rotto = true;
        }
        if(rotto && one)
            return false;

        if(!one)
            fin = true;
        else if(fin)
            return false;
    }
    return tl != make_pair(-1, -1);
}

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        bool f = fun();
        cout << f << "\n";
    }
    return 0;
}