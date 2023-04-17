// Punti: 100.0
#include<bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long N, D, tot = 0;
  fin >> N >> D;
  vector<long long> v(N);

  for(long long &x : v) fin >> x;

  v.push_back(INT_MAX-1);

  for(int i=0; i<N; i++)
  {
    auto up = upper_bound(v.begin(), v.end(), v[i] + D-1);
    tot += up-v.begin()-i-1;
  }
  fout << tot;
  return 0;
}