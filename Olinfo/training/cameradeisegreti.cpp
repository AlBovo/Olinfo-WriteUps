// Punti: 0.0
#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> R, vector<int> B)
{
    ifstream fin("stdin");
    ofstream fout("stdout");

    fin >> N;

    int temp;

    long long somma;

    for(int i=0; i<N; i++)
    {
        fin >> temp;

        R.push_back(temp);
    }
    for(int i=0; i<N; i++)
    {
        fin >> temp;

        B.push_back(temp);
    }

    somma = R[0] + B[0];

    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            somma *= R[i] + B[j];
        }
    }

    fout << somma % 104857601;

    return 0;
}
