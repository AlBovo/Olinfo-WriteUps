// Punti: 100.0
#include<bits/stdc++.h>

using namespace std;

int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N)
{
  int tot = 0;

  for(int i=0; i<M; i++)
  {
    if(L[i] + D[i] + N[i] == 1) tot++;
  }
  return M - tot;
}