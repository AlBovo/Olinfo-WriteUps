// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  
  ll N, I = 1; fin >> N;
  vector<ll> V(N);
  map<ll, bool> m;
  vector<ll> non_trov;

  for(ll i=1; i<=N; i++) fin >> V[i];

  while(!m.count(I) && I <= N && I >= 1)
  {
    m[I] = true;

    I = ((I + V[I]) % N) + 1;
  }

  for(ll i=1; i<=N; i++)
  {
    if(!m.count(i))
    {
      non_trov.push_back(i);
    }
  }

  fout << non_trov.size() << "\n";

  for(ll i : non_trov) fout << i << " ";

  return 0;
}