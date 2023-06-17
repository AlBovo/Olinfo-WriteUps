// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;


int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    long r, c, k;
    long maxStud;

    fin>>r>>c>>k;

    long fitR, fitC;
    
    fitR = c/k;
    fitC = r/k;
    if(c%k>0)
    {
        fitR++;
    }
    if(r%k>0)
    {
        fitC++;
    }

    maxStud = fitC*fitR;
    
    fout<<maxStud;

    return 0;
}