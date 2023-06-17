// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int t, somma;

    fin >> t;

    int n[t];

    for(int i=0; i < t; i++)
    {
        fin >> n[i];
    }

    if(n[0]== -1)
    {
        n[0] = 1;
    }

    for(int e=0; e<t; e++)
    {
        if(n[e]== -1)
        {
            n[e] = n[e-1];
            somma = n[e]+somma;
        }
        else
        {
            somma = n[e] + somma;
        }
    }

    fout << somma;

    return 0;
}
