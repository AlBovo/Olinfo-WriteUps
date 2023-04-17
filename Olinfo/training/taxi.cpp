// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, s = 1000000, prezzo = 0, t;

    fin >> n;

    int N[n];

    for(int i=0; i<n; i++)
    {
        fin >> N[i];
    }

    for(int i=0; i<n; i++)
    {
        if(s+1*i-t>N[i])
        {
            s = N[i];
            prezzo += s;
            t = i;
        }
        else
        {
            prezzo += s + 1*i-t;
        }
    }
    fout << prezzo;
    return 0;
}
