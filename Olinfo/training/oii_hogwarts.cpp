#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class str{
    public:
        int s1;
        int s2;
        int s3;
};

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]){
    queue<int>q;
    vector<vector<str>>v(N);
    vector<int>p(N, (int)10e9);
    q.push(0);
    p[0] = 0;
    for(int i=0; i<M; i++){
        int t = A[i], t1 = B[i], t2 = inizio[i], t3 = fine[i];
        v[t].push_back({t1, t2, t3});
        v[t1].push_back({t, t2, t3});
    }

    while(!q.empty()){
        int r = q.front();
        q.pop();
        for(auto i:v[r]){
            if(p[i.s1] > p[r]+1+max(0, i.s2-p[r]) && p[r] < i.s3){
                p[i.s1] = p[r]+1+max(0, i.s2-p[r]);
                q.push(i.s1);
            }
        }
    }
    if(p[N-1] == (int)10e9){
        return -1;
    }
    return p[N-1];
}
#ifndef EVAL
int main(){
    int n, m; fin >> n >> m;
    int a[m], b[m], s[m], r[m];
    for(int i=0; i<m; i++){
        int t, t1, t2, t3;
        fin >> t >> t1 >> t2 >> t3;
        a[i] = t;
        b[i] = t1;
        s[i] = t2;
        r[i] = t3;
    }
    fout << raggiungi(n, m, a, b, s, r);
    return 0;
}
#endif