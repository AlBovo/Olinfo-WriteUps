// Punti: 69.0
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
void Calcola(int n){
    for(int i=2; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            v[j].push_back(i);
        }
    }
}

void Accendi(int N, int acceso[], int pulsante[]){
    v.resize(N+1);
    Calcola(N);
    for(int i=N; i>=1; --i){
        #ifndef EVAL
        for(int j=1; j<=N; j++)
            cout << acceso[j] << " ";
        cout << "\n";
        #endif
        if(!acceso[i]){
            for(int j=0; j<v[i].size(); j++)
                acceso[v[i][j]] = !acceso[v[i][j]];
            acceso[1] = !acceso[1];
            pulsante[i] = 1;
        }
    }
}

#ifndef EVAL
int main(){
    int n; cin >> n;
    int acceso[n+1], pulsante[n+1] = {0};

    for(int i=1; i<=n; i++)
        cin >> acceso[i];
    Accendi(n, acceso, pulsante);
    for(int i=1; i<=n; i++){
        cout << pulsante[i] << " ";
    }
    return 0;
}
#endif