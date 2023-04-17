// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, e = 0, somma = 0;

    fin >> N;

    int V[N];

    for(int i = 0; i<N; i++)
    {
        fin >> V[i];

        somma += V[i];
    }

	sort(V, V+N, less<int>());

	while(somma < 1)
	{
	    somma += 2*(V[e]*-1);
		e++;
	}

    fout << e;

    return 0;
}
