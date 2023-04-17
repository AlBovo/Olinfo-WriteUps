// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int organizza(int N, int X, int Y, vector<int> A, vector<int> B)
{
  long long int k = 0, mini = INT_MAX;
  bool boh1 = true, boh2 = true;

  map<long long, long long> M;

  for(int i=0; i<N; i++)
  {
    long long int k1, k2;
    if(A[i] <= X) k1 = X;
    else if(A[i] > Y) k1 = -1;
    else k1 = A[i];

    if(B[i] >= Y) k2 = Y;
    else if(B[i] < X) k2 = -1;
    else k2 = B[i];
    
    if(k1 == X) boh1 = false;
    if(k2 == Y) boh2 = false;

    if(k1 != -1 && k2 != -1)
    {
        M[k1]++;
        M[k2+1]--;
    }
  }
  
  if(boh1 || boh2) return N;
  
  for(auto i : M)
  {
    if(Y < i.first) return N-mini;
    k += i.second;
    mini = min(k, mini);
    //cout << k << " " << mini << "\n";
  }
  //cout << N-mini;
  return N;
}
