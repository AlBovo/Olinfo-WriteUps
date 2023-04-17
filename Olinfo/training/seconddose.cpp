// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, n1, k = 0;

    fin >> n >> n1;

    int v[n+n1];

    for(int i=0; i<n+n1; i++)
    {
        fin >> v[i];
    }

    sort(v, v +(n+n1));

    for(int i=0; i<n+n1-1; i++)
    {
        if(v[i] == v[i+1])
        {
            k++;
        }
    }

    fout << k;
    return 0;
}
