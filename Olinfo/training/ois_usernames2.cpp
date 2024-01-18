// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

int main(){
    string nome; cin>>nome;
    long long N; cin >> N;
    unordered_set<string>nomi;
    string a;
    for(int i=0;i<N;i++){
        cin>>a; nomi.insert(a);
    }
    
    if(nomi.count(nome)==0) cout<<nome;
    else{
        for(int i=1;i<=N;i++){
            if(nomi.count(nome + to_string(i))==0){
                nome += to_string(i);
                break;
            }
        }
        cout<<nome;
    }
    return 0;
}