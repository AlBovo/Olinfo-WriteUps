// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, k = 1, U = 0, lettere = 26;

    fin >> N;

    char temp;

    vector<char> S;

    for(int i=0; i<N; i++)
    {
        fin >> temp;

        if(temp == '_')
        {
            U++;
        }
        else
        {
            S.push_back(temp);
        }
    }

    lettere -= S.size();

    for(int i=0; i<U; i++)
    {
        k *= lettere;

        lettere -= 1;
    }

    fout << k;

    return 0;
}
