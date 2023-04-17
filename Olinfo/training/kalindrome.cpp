// Punti: 100.0
#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int N;
string s;

bool prova(int k)
{
  vector<string> t;
  string t1 = "";
  for(int i=0; i<=s.size()-k; i+=k)
  {
    t.push_back(s.substr(i, k));
  }
  for(int i=t.size()-1; i>=0; i--)
  {
    t1 += t[i];
  }
  return t1 == s;
}

int main()
{
  fin >> N >> s;

  for(int i=1; i<=N; i++)
  {
    if(N%i==0) 
    {
      if(prova(i))
      {
        cout << i; 
        return 0;
      } 
    }
  }

  return 0;
}