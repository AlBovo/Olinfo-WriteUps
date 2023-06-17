// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, k, gustomassimo = -1001, temp = 0;

    fin >> n >> k;

    int M[n];

    for(int i=0; i<n; i++)
    {
        fin >> M[i];
    }

    for(int i=0; i<k; i++)
    {
        temp += M[i];
    }
    gustomassimo = temp;

    for(int i=k; i<=n-k; i++)
    {
        temp += M[i];
        temp -= M[i-k];

        if(temp > gustomassimo)
        {
            gustomassimo = temp;
        }
    }

    fout << gustomassimo;

    return 0;
}
