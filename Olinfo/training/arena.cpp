// Punti: 100.0
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, E, L; cin >> N >> E >> L;
    int sa = 0;
    unordered_map<int, int> vite;
    for(int i=0; i<N; i++) vite[i] = L;
    for(int i=0; i<E; i++)
    {
        int k, m;
        char a;

        cin >> k >> a;

        if(a == 'f'){
            cin >> m;
            vite[m]--;
        }
        else if(a == 'e'){
            sa++;
            vite[k]++;
        }
    }
    int tot = 0;
    for(auto i : vite) if(i.second-sa > 0) tot++;
    cout << tot;
    return 0;
}