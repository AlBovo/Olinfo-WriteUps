// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, k, sommaMax = 0, somma = 0, sos = 1;

    fin >> n;

    for(int i=1; i<=n; i++)
    {

        for(int e=0; e<=n; e++)
        {
            fin >> k;

            somma += k;
        }
        somma++;

        if(sommaMax < somma)
        {
            sommaMax = somma;
            sos = i;
        }

        fout << sos << endl;

        somma = 0;
    }

    return 0;
}
