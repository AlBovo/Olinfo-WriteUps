// Punti: 100.0
#include<bits/stdc++.h>

using namespace std;

int presta(int N, int C, vector<int> P)
{
  int tot = 0, count = 0;
  sort(P.begin(), P.end(), greater<int>());

  while(C > 0)
  {
    C -= P[count];
    count++;
    tot++;
  }

  return tot;
}