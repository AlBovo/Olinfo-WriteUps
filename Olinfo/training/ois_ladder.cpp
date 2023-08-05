// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, nmax = 0;

    fin >> n;

    long P[n];
    
    for(int i=0; i<n; i++)
    {
        fin >> P[i];
    }
    
    if(n == 2)
    {
        nmax = P[0];
        if(P[1]-P[0] > nmax)
        {
            fout << P[1]-P[0];
            return 0;
        }
    }
    
    nmax = P[0];

    for(int i=1; i<n; i++)
    {
        if(P[i+1]-P[i] > nmax)
        {
            nmax = P[i+1]-P[i];
        }
    }

    fout << nmax;
    return 0;
}
