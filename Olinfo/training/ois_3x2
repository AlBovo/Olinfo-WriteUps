// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int N, m = 0, x = 0;
    fin >> N;
    int P[N];

    for(int i = 0; i < N; i++)
    {
        fin >> P[i];
    }

    int n = sizeof(P) / sizeof(P[0]);

    sort(P, P + n, greater<int>());

    for(int i = 1; i <= N; i++)
    {
        if(i%3 != 0)
        {
            m += P[i-1];
        }
    }

    fout << m;

    return 0;
}
