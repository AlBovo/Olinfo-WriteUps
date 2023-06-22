// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, n1 = 0;

    fin >> n >> m;

    int P[n];
    int C[n];

    for(int i=0; i<n; i++)
    {
        fin >> P[i];
    }
    for(int i=0; i<n; i++)
    {
        fin >> C[i];
    }

    for(int i=0; i<n; i++)
    {
        if(P[i]<= m)
        {
            n1++;
            m -= P[i];
        }
        else
        {
            m += C[i];
        }
    }

    fout << n1 << " " << m;

    return 0;
}
