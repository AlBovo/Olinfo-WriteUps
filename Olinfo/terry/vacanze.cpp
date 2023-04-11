#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");
set<map<int, int>>sol;
vector<set<int>>gra;

void trova(map<int, int>&s, int pos){ // mettere vector per contare tipo {1: 2, 2:1, 3:1, 4:2} il primo numero è il nodo il secondo il numero di volte che ci sono passato (entrato + uscito = 2)
    if(s.size() == 4){
        for(auto i:s){
            int maxi = 0;
            for(auto e:s){
                if(i.first != e.first){
                    maxi += gra[i.first].count(e.first);
                }
            }
            if(maxi != 2){
                return;
            }
        }

        vector<int>p;
        for(auto i:s){
            if(i.second == 1){
                p.push_back(i.first);
            }
        }
        if(p.size() == 2){
            if(gra[p[0]].count(p[1])){
                s[p[0]]++;
                s[p[1]]++;
                if(!sol.count(s)){
                    sol.insert(s);
                }
                s[p[0]]--;
                s[p[1]]--;
            } 
        }
        return;
    }
    for(int i:gra[pos]){
        if(!s.count(i)){
            s[pos]++;
            s[i]++;
            trova(s, i);
            s[pos]--;
            s.erase(i);
        }
    }
}

int main(){
    int t; fin >> t;
    for(int e=0; e<t; e++){
        int n, m; fin >> n >> m;
        gra.resize(n+1);
        for(int i=0; i<m; i++){
            int t1, t2; fin >> t1 >> t2;
            gra[t1].insert(t2);
            gra[t2].insert(t1);
        }
        /*
        for(int i=0; i<n; i++){
            cout << i << ": ";
            for(int f:gra[i]){
                cout << f << " ";
            }
            cout << endl;
        }
        return 0;
        */
        for(int i=0; i<n; i++){
            map<int, int>se;
            se[i] = 0;
            trova(se, i);
        }
        fout << "Case #" << e+1 << ": " << sol.size() << "\n";
        sol.clear();
        gra.clear();
    }
    return 0;
}