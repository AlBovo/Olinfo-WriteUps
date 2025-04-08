// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int traffico(int N, vector<int> S) {
    int res = 1e9;
    for(int i=0; i<2; i++){
        int tot = 0;
        for(int e=0; e<N; e++){
            if(!i && e % 2 == 0 && S[e] % 2 != 0)
                tot++;
            if(!i && e % 2 != 0 && S[e] % 2 == 0)
                tot++;
            if(i && e % 2 == 0 && S[e] % 2 == 0)
                tot++;
            if(i && e % 2 != 0 && S[e] % 2 != 0)
                tot++;
        }
        res = min(res, tot);
    }

    return res;
}

// NON TOCCARE SOTTO QUESTA LINEA

#ifndef EVAL

int main() {
    int N; cin >> N;

    vector<int> S(N);

    for (auto &s: S) {
        cin >> s;
    }

    cout << traffico(N, S) << endl;
}

#endif
