// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;

    fin >> n;

    int S[n];
    int D[n];

    for(int i=0; i<n; i++)
    {
        fin >> S[i];
        fin >> D[i];
    }

    for(int i=0; i<n-1; i++)
    {
        if(S[i]>D[i+1] || S[i+1]>D[i])
        {
            fout << "NO";
            return 0;
        }
    }
    fout << "YES";
    return 0;
}
