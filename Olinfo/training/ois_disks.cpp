// Punti: 50.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long s, e, tot, tot2 = 0;
    fin >> s >> e >> tot;

    long long alg = e - s;
    tot -= 24 - e;
    tot2 += (long long)(tot / 24LL) * alg;
    tot -= (long long)(tot / 24LL) * 24LL;
    if(tot > 0){
        tot -= s;
        tot2 += min(tot, alg);
    }
    fout << tot2;
    return 0;
}