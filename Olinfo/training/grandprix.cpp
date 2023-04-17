// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int N, M, primo, t; fin >> N >> M;
    for(int i=0; i<N; i++)
    {
        fin >> t;
        if(!i) primo = t;
    }

    for(int i=0; i<M; i++)
    {
        int A, B; fin >> A >> B;

        if(B == primo) primo = A;
    }

    fout << primo;
    return 0;
}