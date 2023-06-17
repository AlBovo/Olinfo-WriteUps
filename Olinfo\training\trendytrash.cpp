// Punti: 100.0
#include<vector>
#include<string>
using namespace std; 

int pulisci(int N, int M, vector<string> S){
    int n = N, m = M;
    int mat[N][M];
    vector<int>r(N, 0), c(M, 0);
    for(int i=0; i<N; i++){
        for(int e=0; e<M; e++){
            mat[i][e] = S[i][e]-'0';
            r[i] += mat[i][e];
            c[e] += mat[i][e];
        }
    }
    int tot = 0;
    while(n > 0 && m > 0){
        bool fatto = false;
        for(int i=0; i<r.size(); i++){
            if(r[i] == 0 || r[i] == m){
                fatto = true;
                tot += m;
                if(r[i] == m){
                    for(int e=0; e<c.size(); e++){
                        c[e] -= 1;
                    }
                }
                n--;
                r[i] = -1;
            }
        }
        for(int i=0; i<c.size(); i++){
            if(c[i] == 0 || c[i] == n){
                fatto = true;
                tot += n;
                if(c[i] == n){
                    for(int e=0; e<r.size(); e++){
                        r[e] -= 1;
                    }
                }
                m--;
                c[i] = -1;
            }
        }
        if(!fatto){
            break;
        }
    }
    return (N*M)-tot;
}

#ifndef EVAL
int main(){
    int n, m;
    fin >> n >> m;
    vector<string>v(n);
    for(auto &i:v){
        fin >> i;
    }
    cout << pulisci(n, m, v);
    return 0;
}
#endif