#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int t; fin >> t;
    for(int r=0; r<t; r++){
        int n, m, k, a, b; fin >> n >> m >> k >> a >> b;
        vector<vector<int>>v(n, vector<int>(m, 0)), sum(n, vector<int>(m, 0));
        for(int i=0; i<k; i++){
            int t1, t2; fin >> t1 >> t2;
            v[t1][t2]++;
        }
        for(int i=0; i<n; i++){
            for(int e=0; e<m; e++){
                if(!e){
                    sum[i][e] = v[i][e];
                }
                else{
                    sum[i][e] = v[i][e] + sum[i][e-1];
                }
            }
        }
        int mini = (int)10e8;
        for(int i=0; i<=n-a; i++){
            for(int e=b-1; e<m; e++){
                int tot = 0;
                for(int j=0; j<a; j++){
                    if(e != b-1){
                        tot += sum[i+j][e] - sum[i+j][e-b];
                    }
                    else{
                        tot += sum[i+j][e];
                    }
                }
                mini = min(mini, tot);
            }
        }
        fout << "Case #" << r+1 << ": " << mini << "\n";
    }
    return 0;
}