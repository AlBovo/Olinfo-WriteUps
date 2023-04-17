// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int mani = 0, N, presenti = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream fin("input.txt");
  cin >> N;

  map<long long int, int> m;

  for(long long int i=0; i<N; i++)
  {
    long long int t, t1;
    cin >> t >> t1;

    m[t]++;
    m[t1]--;
  }

  for(auto i : m)
  {
    if(i.second == -1)
    {
      presenti += i.second;
      mani += presenti;
    } 
    else
    {
      mani += presenti;
      presenti += i.second;
    }
    //cout << presenti << " " << mani << " " << i.second << "\n";
  }

  cout << mani;

  return 0;
}