// Punti: 0.0
#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

struct prob{
    long double p;
    long double pi;
    long c;
};

long double fast_exp(long double b, long e){
    if(e == 1){
        return b;
    }
    if(e == 0){
        return 1;
    }
    long double t = fast_exp(b, e/2);
    if(e % 2 == 0){
        return t * t;
    }
    else{
        return t * t * b;
    }
}
bool getSorted(prob a, prob b){
    return a.p < b.p;
}

int main(){
    fstream::sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    fout << fixed << setprecision(6) << "";
    long t; fin >> t;
    for(long e=0; e<t; e++){
        long n, m; fin >> n >> m;
        vector<prob>v(n);
        for(auto &i:v){
            fin >> i.p;
            i.pi = i.p;
            i.c = 1;
        }
        sort(v.begin(), v.end(), getSorted);

        long double tot = 0;
        for(long i=0; i<m; i++){
            tot += v[n-1].p;
            //cout << v[n-1].first << " " << tot << " " << v[n-1].second << " ";
            v[n-1].p = v[n-1].p * fast_exp(1 - v[n-1].p, v[n-1].c);
            v[n-1].c++;
            //cout << v[n-1].first << "\n";
            auto temp = v[n-1];
            sort(v.begin(), v.end(), getSorted);
            //v.erase(v.begin()+n-1);
            //long pos = lower_bound(v.begin(), v.end(), temp) - v.begin();
            //v.insert(v.begin()+pos, temp);
        }
        fout << tot << "\n";
    }
    return 0;
}