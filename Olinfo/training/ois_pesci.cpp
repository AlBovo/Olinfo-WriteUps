// Punti: 10.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long int dir = 3, N, t1, t2;
  fin >> N;
  stack<long long int> q;

  for(int i=0; i<N; i++)
  {
    fin >> t1 >> t2;

    if(t1 != dir)
    {
      while(!q.empty())
      {
        if(q.top() < t2) q.pop();
        else break;
      }
      if(q.empty())
      {
        q.push(t2);
        dir = t1;
      }
    }
    else
    {
      q.push(t2);
    }
  }

  fout << q.size();

  return 0;
}