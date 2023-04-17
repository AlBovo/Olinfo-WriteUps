// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, somma, a, b = 0;

    fin >> n;

    fin >> a >> b;

    somma = a-b;

    for(int i=1; i<n; i++)
    {
        fin >> a;

        if(b-a > somma)
        {
            somma = b-a;
        }
        if(a-b > somma)
        {
            somma = a-b;
        }

        fin >> b;

        if(a-b > somma)
        {
            somma = a-b;
        }
    }

    fout << somma;
    return 0;
}