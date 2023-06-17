// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    int lunghezza = 1;

    fin >> n;

    while(n != 1)
    {
        if(n%2==0)
        {
            n = n/2;
        }
        else
        {
            n = n*3+1;
        }
        lunghezza++;
    }

    fout << lunghezza;
    return 0;
}
