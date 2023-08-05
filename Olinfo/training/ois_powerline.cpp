// Punti: 30.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int T, total = 0, temp = 0;
    int temp1;

    fin >> T;

    long S[T];

    for(int i=0; i<T; i++)
    {
        fin >> S[i];
    }

    bool sos = true, primo;

    while(sos)
    {
        primo = true;
        sos = false;
        for(int i=0; i<T-1; i++)
        {
            if(S[i]<S[i+1] && primo)
            {
                total++;

                S[i] = S[i+1];

                sos = true;
                primo = false;
            }
            if(S[i] < S[i+1])
            {
                S[i] = S[i+1];
            }
        }
    }

    fout << total;

    return 0;
}
