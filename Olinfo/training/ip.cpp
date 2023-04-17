// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long N = 1;

    char bin;

    long IP1[4];
    long IP2[4];

    for(int i=0; i<3; i++)
    {
        fin >> IP1[i];
        fin >> bin;
    }
    fin >> IP1[3];

    for(int i=0; i<3; i++)
    {
        fin >> IP2[i];
        fin >> bin;
    }
    fin >> IP2[3];

    for(int s=3,i=0; i<4; i++,s--)
    {
        if(IP1[i] != IP2[i])
        {
            N += (IP2[i]-IP1[i]) * pow(256, s);
        }
    }
    cout << N;
    return 0;
}