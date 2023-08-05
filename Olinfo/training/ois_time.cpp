// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int H0, H1, H2;
    int N0, N1, N2;

    fin >> H0;
    fin >> N0;
    fin >> H1; 
    fin >> N1;

    N0 = H0 * 60 + N0;
    N1 = H1 * 60 + N1;

    int oramin = 0;
    int ora = 0;

    if(N0 > N1)
    {
        oramin = 1440 - N0 + N1;
    }
    else
    {
        oramin = N1 - N0;
    }
    
    H2 = oramin / 60;
    N2 = oramin % 60;
    
    fout << H2 << " " << N2;
    return 0;
}
