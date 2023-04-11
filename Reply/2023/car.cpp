#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class car{
    public:
        long long id;
        long long s;
        long long t;
        long long c;
        long long d;
};

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long t; fin >> t;
    for(long long i=0; i<t; i++){
        pair<long long,long long> idbest = {(long long)10e14, (long long)10e14}; // id / time
        long long r, n; fin >> r >> n;
        for(long long e=0; e<n; e++){
            long long id, s, t, c, d, n1 = r, tot = 0; fin >> id >> s >> t >> c >> d;
            while(n1 > 0){
                if(n1 <= t*d){
                    tot += (long long)(n1/t);
                    break;
                }
                else{
                    n1 -= t*d;
                    tot += d;
                }
                if(n1 < s*c){
                    tot += (long long)(n1/s);
                    break;
                }
                else{
                    n1 -= s*c;
                    tot += c;
                }
            }

            if(tot < idbest.second){
                idbest.first = id;
                idbest.second = tot;
            }  
            else if(tot <= idbest.second && id < idbest.first){
                idbest.first = id;
                idbest.second = tot;
            }
        }
        fout << "Case #" << i+1 << ": " << idbest.first << "\n";
    }
    return 0;
}
