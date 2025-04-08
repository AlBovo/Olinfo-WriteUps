// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int compila(int D, int X, int N, int S) {
    long long tot = N * S;
    X -= D - tot;
    if (X <= 0)
        return 0;
    return X / S + (X % S > 0);
}

// NON TOCCARE SOTTO QUESTA LINEA

#ifndef EVAL

int main() {

    int D, X, N, S;
    cin >> D >> X >> N >> S;

    cout << compila(D, X, N, S) << endl;
}

#endif
