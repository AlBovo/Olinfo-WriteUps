// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, T, k = -1;

    fin >> N >> T;

    pair<int,int>A[N];

    for(int i=0; i<N; i++)
    {
        fin >> A[i].first;
        fin >> A[i].second;
    }

    for(int i=0; i<N; i++)
    {
        if(i != N-1 && (24-A[i].second)+A[i+1].first >= T)
        {
            k = i;
        }
    }

    cout << k;

    return 0;
}
