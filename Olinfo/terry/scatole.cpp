#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map<pair<int, int>, string>dpV;

bool isPossible(int p, int s){
    int t = (int)sqrtl((p + s) * 2);
    return (p + s) * 2 == t * (t+1);
}

bool dp(int p, int s, int d){
    if(p < 0 || s < 0 ){
        dpV[{p, s}] = "NO";
        return false;
    }
    if(dpV.count({p, s}))
        return dpV[{p, s}] != "NO";

    if(dp(p - d, s, d+1)){
        dpV[{p, s}] = "1" + dpV[{p-d, s}];
        return true;
    }
    if(dp(p, s-d, d+1)){
        dpV[{p, s}] = "2" + dpV[{p, s-d}];
        return true;
    }
    dpV[{p, s}] = "NO";
    return false;
}

int main(){
    int t; fin >> t;
    for(int e=0; e<t; e++){
        int p, s; fin >> p >> s;
        if(!isPossible(p, s)){
            fout << "Case #" << e+1 << ": " << "IMPOSSIBILE" << "\n";
            continue;
        }
        dpV[{0, 0}] = "";
        fout << "Case #" << e+1 << ": " << (dp(p, s, 1) ? dpV[{p, s}] : "IMPOSSIBILE") << "\n";
        dpV.clear();
    }
    return 0;
}