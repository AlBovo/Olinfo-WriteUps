// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, n1 = 0;

    fin >> n;

    int D[n];

    for(int i=0; i<n; i++)
    {
        fin >> D[i];
    }

    int s = sizeof(D) / sizeof(D[0]);

    std::sort(D, D + n, std::greater<int>());

    for(int i=0; i<n-1; i++)
    {
        if(D[i]>D[i+1])
        {
            n1++;
        }
    }

    if(n1 == n-1)
    {
        fout << "Ok";
        return 0;
    }
    else
    {
        fout << "Impossible";
        return 0;
    }

    return 0;
}
