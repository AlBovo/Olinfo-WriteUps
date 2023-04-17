// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int distanza;
    int potenza;
    int numeroSalti = 0;

    fin >> distanza;

    while(distanza > 0)
    {
        potenza = 0;
        while(pow(2, potenza) <= distanza)
        {
            potenza++;
        }
        distanza = distanza - pow(2, potenza - 1);
        numeroSalti++;
    }
    fout << numeroSalti;
    return 0;
}