#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
struct stud{
    int p;
    int e;
    int g;
};
bool sorta(stud &a, stud &b){
    return a.p > b.p;
}
int maxi = 0;
vector<stud>v;
void prova(int n, int e, int p, int tot, vector<bool>&ut){
    if(n == 0 || e == 0){
        maxi = max(maxi, tot);
        return;
    }
    for(int i=0; i<ut.size(); i++){
        if(p == 0 && v[i].g) continue;
        if(e < v[i].e) continue;
        if(ut[i]) continue;
        ut[i] = true;
        prova(n-1, e-v[i].e, p-v[i].g, tot+v[i].p, ut);
        ut[i] = false;
    }
    maxi = max(maxi, tot);
}

int main(){
    int t; fin >> t;
    for(int f=0; f<t; f++){
        maxi = 0;
        long long k, n, e, p; fin >> k >> n >> e >> p;
        v.clear();
        v.resize(k);
        for(int i=0; i<k; i++){
            stud e;
            fin >> e.p >> e.e >> e.g;
            v[i] = e; 
        }
        vector<bool>us(k, 0);
        sort(v.begin(), v.end(), sorta);
        prova(n, e, p, 0, us);
        fout << "Case #" << f+1 << ": " << maxi << "\n";
    }
    return 0;
}