// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N, L, M;
  fin >> N >> L;
  
  vector<string> V;
  unordered_map<string, int> R;
  string temp;

  for(int i=0; i<N; i++)
  {
    if(!i)
    {
      fin >> M;

      for(int i=0; i<M; i++)
      {
        fin >> temp;
        V.push_back(temp);
        R[temp] = 0;
      }
    }
    else
    {
      fin >> M;
      unordered_map<string, bool> s;
      for(int i=0; i<M; i++)
      {
        fin >> temp;
        if(!s.count(temp))
        {
          R[temp]++;
          s[temp] = true;
        }
      }
    }
  }

  for(string i : V) cout << R[i] << " ";

  return 0;
}
