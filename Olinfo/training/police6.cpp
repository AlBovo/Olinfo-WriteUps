// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool sorta(pair<ll, int>a, pair<ll, int>b)
{
  return a.first < b.first;
}

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  ll N, M, L, k = 0, mini = pow(10,5) + 1; fin >> N >> M >> L;
  bool first = true;
  
  map<ll, int>m;
  vector<pair<ll,int>>P;

  for(int i=0; i<N; i++)
  {
    ll temp, k1, k2; fin >> temp;

    if(temp-M > 0) k1 = temp-M;
    else k1 = 0;

    if(temp+M < L) k2 = temp+M;
    else k2 = L;

    P.push_back({k1, 0});
    P.push_back({k2, 1});
  }

  sort(P.begin(), P.end(), sorta);

  for(int i=0; i<P.size(); i++)
  {
    if(first && P[i].first > 0)
    {
      fout << 0;
      return 0;
    }
    else if(first) first = false;

    if(i == P.size()-1 && P[i].first < L)
    {
      fout << 0;
      return 0;
    }


    if(P[i].second)
    {
      m[P[i].first]--;
    }
    else
    {
      m[P[i].first]++;
    }
  }
  
  for(auto i : m)
  {
    if(i.first == L) break;

    k += i.second;
    mini = min(k, mini);
  }
  cout << mini;

  return 0;
}