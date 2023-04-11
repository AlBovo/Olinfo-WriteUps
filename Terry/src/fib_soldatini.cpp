#include <bits/stdc++.h>
#pragma GCC optimze("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    fin.sync_with_stdio(0);
    fout.sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    long long t; fin >> t;
    for(long long e=0; e<t; e++){
        long long n, tot = -1; fin >> n;
        string s = "";
        for(int i=0; i<n; i++){
            char r; fin >> r;
            s += r;
        }
        cout << s << " ";
        vector<long long>q;
        for(long long i=0; i<n; i++){
            if(s[i] == '0'){
                q.push_back(i);
            }
        }
        if(q.empty()){
            fout << "Case #" << e+1 << ": " << n << "\n";
            continue; 
        }
        q.push_back(n);
        for(int i=0; i<q.size(); i++){
            int pos = q[i];
            if(!pos){
                tot = max(tot, q[i+1]-pos);
            }
            else if(i < q.size()-1){
                tot = max(tot, q[i+1]-pos + (pos-1-q[i-1]));
            }
        }

        fout << "Case #" << e+1 << ": " << tot << "\n";
    }

    return 0;
}
