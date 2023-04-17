// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");
    //
  long long int N, massimo = -1, somma = 0;
  fin >> N;

  for(int i=0; i<N; i++)
  {
    int temporaneo;
    fin >> temporaneo;

    if(i == 0)
    {
      massimo = temporaneo;
      somma += massimo;
    }
    else if(temporaneo > massimo)
    {
      massimo = temporaneo;
      somma += massimo;
    }
  }
  fout << somma;
  return 0;
}
