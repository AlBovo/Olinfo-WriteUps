// Punti: 15.79
#include<bits/stdc++.h>
using namespace std;
struct node{
    long long begin;
    long long end;
};
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    long long n; fin >> n;
    vector<node>v(n);
    sort(v.begin(), v.end(), [&](node a, node b){
        return a.begin > b.begin;
    });
    
    for(auto &i : v) 
        fin >> i.begin >> i.end;
    long long last = 0, best = v[0].end, tot = 0;
    for(long long i=1; i<n; ){
        if(v[i].begin <= v[last].end){
            if(best < v[i].end)
                best = v[i].end;
            i++;
        }
        else{
            tot++;
            while(i < n && v[i].begin <= best)
                i++;
            last = i; 
            if(i < n){
                best = v[last].end;
            }
        }
    }
    fout << ((last == n) ? tot : tot + 1);
    return 0;
}