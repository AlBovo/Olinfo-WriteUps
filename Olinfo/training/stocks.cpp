// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long int N, somma = 0, sommaMax = 0, last; fin >> N;
  long long int A[N];
  long long int S[N];

  for(int i=0; i<N; i++) fin >> A[i];
  for(int i=0; i<N; i++) fin >> S[i];

  for(int i=0; i<N; i++)
  {
    if(S[i])
    {
      do
      {
        //cout << A[i] << " ";
        last = A[i];
        somma += A[i];
        i++;
      } while (A[i] >= last && i<N && S[i]);

      sommaMax = max(somma, sommaMax);
    }
    if(i < N && S[i]) i--;

    somma = 0;
  }
  
  fout << sommaMax;
  return 0;
}