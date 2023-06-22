// Punti: 100.0
#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool prova()
{
  int n, k, t; fin >> n >> k;
  stack<int> q;
  for(int i=0; i<n; i++)
  {
    fin >> t;
    if(q.empty()) q.push(t);
    else if(q.top() == t) q.pop();
    else if(q.top() != t) q.push(t);
  }
  return q.empty();
}

int main()
{
  int N; fin >> N;

  for(int i=0; i<N; i++) fout << prova() << "\n";

  return 0;
}