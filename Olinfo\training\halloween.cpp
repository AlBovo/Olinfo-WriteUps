// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    long long n, m;
    long somma, o, resto;

    fin >> n >> m;

    long long Bamb[n];

    for(int i=0; i<n; i++)
    {
        fin >> Bamb[i];
        somma += Bamb[i];
    }
    resto = m%somma;
    
    if(resto == 0)
    {
        fout << n-1;
        return 0;
    }

    for(int i=0; i<n && resto>0; i++)
    {
        resto -= Bamb[i];
        o = i;
    }
    fout << o;

    return 0;
}
