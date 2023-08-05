// Punti: 58.0
#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int N, intr = -1; cin >> N;
  vector<int>V(N);
  for(int &x : V) cin >> x;

  for(int i=0; i<N; i++)
  {
    for(int e=i+1; e<N; e++)
    {
      intr = max(intr, abs(V[i] - V[e]) + abs(i-e));
    }
  }
  cout << intr;
  return 0;
}