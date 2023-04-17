// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long long int N, pre = 1, tot = 1; fin >> N;

    for(int i=0; i<N; i++)
    {
        long long int temp; fin >> temp;
        tot += pre * temp;
        pre = pre * temp;
    }

    cout << tot;

    return 0;
}