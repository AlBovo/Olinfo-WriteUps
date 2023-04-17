// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    long long int T, a, b, ris;
    string ot;
    fin >> T;
    for(int i = 0; i < T; i++)
    {
        fin >> a;
        fin >> b;
        if(a > 0 && b > 0)
        {
            ot = "+";
        }
        else if(a <= 0 && b >= 0)
        {
            ot = "0";
        }
        else
        {
            if((a - b) % 2 == 0)
            {
                ot = "-";
            }
            else
            {
                ot = "+";
            }
        }
        fout << ot << endl;
    }

    return 0;
}