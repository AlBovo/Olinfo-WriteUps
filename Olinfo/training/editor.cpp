// Punti: 0.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    char sus[4] = {'n', 'i', 'N', 'I'};

    int n, italic = 0, bold = 0;

    fin >> n;

    char sos[n];

    for(int i=0; i<n; i++)
    {
        fin >> sos[i];

        if(sos[i]== 'I' or sos[i]=='i')
        {
            italic++;
        }
        if(sos[i] == 'I' or sos[i] == 'N')
        {
            bold++;
        }
    }

    n = min(italic,bold);

    cout << n;

    return 0;
}
