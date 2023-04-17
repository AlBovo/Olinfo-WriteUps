// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;
    char S[N];
    string qw = "qwertyuiopasdfghjklzxcvbnm";
    string out = "";

    for(int i=0; i<N; i++)
    {
        fin >> S[i];
    }

    for(int i=0; i<N; i++)
    {
        if(S[i] != 'p' && S[i] != 'l' && S[i] != 'm')
        {
            for(int e=0; e<qw.size(); e++)
            {
                if(qw[e] == S[i])
                {
                    out += qw[e+1];
                }
            }
        }
    }

    cout << out;
    return 0;
}
