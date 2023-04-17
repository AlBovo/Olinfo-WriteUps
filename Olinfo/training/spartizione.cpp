// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int g, p, g1 = 0, t = 1;

    fin >> g >> p;

    while(g > 0)
    {
        if(t>=g)
        {
            g1 += g;
            g = 0;
            fout << g1;
            return 0;
        }
        
        g1 += t;
        g -= t+p-1;
        t++;
    }

    fout << g1;
    return 0;
}
