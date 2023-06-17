// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, nmax=0, nmin=0, t=0, out=0, coun=0;

    fin >> n;

    int S[n];

    for(int i=0; i<n; i++)
    {
        fin >> S[i];
    }

    nmin = S[0];
    nmax = S[0];
    for(int i=1; i<n; i++)
    {
        nmin -= 1;
        if(nmin>S[i])
        {
            t += (nmin - S[i]);
            nmin = S[i];
            coun++;
        }

    }
    out = nmax - t;
    fout << out << " " << coun;

    return 0;
}
