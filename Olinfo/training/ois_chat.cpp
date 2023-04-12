#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    queue<string> q;
    map<string, bool>m;
    int N; fin >> N;
    string k[N];
    for(int i=0; i<N; i++){
        fin >> k[i];
    }

    for(int i=N-1; i >= 0; i--){
        string temp = k[i];
        if(!m.count(temp)){
            m[temp] = true;
            q.push(temp);
        }
    }
    while(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
    }
    return 0;
}
