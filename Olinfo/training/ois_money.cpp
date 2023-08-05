// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n, m; fin >> n >> m;
    vector<pair<int, int>> v(n); // val, indx
    for(int i=0; i<m; i++){
        int t, t1, t2; fin >> t >> t1 >> t2;
        v[t] = {v[t].first-t2, t};
        v[t1] = {v[t1].first+t2, t1};
    }
    sort(v.begin(), v.end());
    
    /*for(auto i : v){
        cout << i.first << " " << i.second << "\n";
    }*/
    int pos = -1;
    for(int e=0; e<v.size(); e++){
        if(v[e].first > 0){
            pos = e;
            break;
        }
    }
    vector<string>s;
    bool boh = true;
    for(int i=0; i<v.size(); i++){
        if(v[i].first < 0){
            boh = true;
            while(v[i].first < 0 && boh){
                int it;
                if(pos < v.size()){
                    it = pos;
                    ++pos;
                    if(abs(v[i].first) >= v[it].first){
                        int t = v[it].first;
                        v[i].first += t;
                        v[it].first = 0;
                        s.push_back(to_string(v[it].second) + " " + to_string(v[i].second) + " " + to_string(t));
                    }
                    else{
                        int t = v[i].first;
                        v[it].first += v[i].first;
                        v[i].first = 0;
                        s.push_back(to_string(v[it].second) + " " + to_string(v[i].second) + " " + to_string(abs(t)));
                        pos -= 1;
                    }
                }
                else{
                    boh = false;
                }
            }
        }
    }
    fout << s.size() << endl;
    for(auto i : s){
        fout << i << endl;
    }
    return 0;
}