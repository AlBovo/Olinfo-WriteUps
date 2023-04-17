// Punti: 100.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

set<long long>s;
void inizia(){
}

void apri(long long p){
    s.insert(p);
}

void chiudi(long long p){
    s.erase(p);
}

long long chiedi(long long p){
    if(s.size() == 0){
        return -1;
    }
    auto M = s.upper_bound(p), m = --s.upper_bound(p);
    if(M == s.end()){
        if(m == s.end()){
            return -1;
        }
        else{
            return *m;
        }
    }
    else{
        if(m == s.end()){
            return *M;
        }
        else if(abs(p-*M) == abs(p-*m)){
            return *M;
        }    
        else if(abs(p-*M) > abs(p-*m)){
            return *m;
        }
        else{
            return *M;
        }
    }
} 
#ifndef EVAL
int main() {
    int Q;
    fin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        fin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}
#endif