// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int N, M, E;

int main() {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    fin >> N;
    fin >> M;
    fin >> E;
    int magDiv = 0;
    for(int i = 0; i <= N - M; i++)
    {
        if(magDiv < E%(M+i))
        {
            magDiv = E%(M+i);
        }
    }
    fout << magDiv;

    return 0;
}