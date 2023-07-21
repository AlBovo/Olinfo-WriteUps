// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long int is = 0, N;
  bool isb = false;
  fin >> N;
  string temp;

  while(getline(fin, temp))
  {
    map<char, long long int>m;
    for(int i=0; i<temp.size(); i++)
    {
      isb = true;
      char t = tolower(temp[i]);
      //cout << t << " ";
      if(t != ' ' && t >= 'a' && t <= 'z')
      {
        if(m.count(t) == 0)
        {
          m[t] = 1;
        }
        else
        {
          m[t]++;
          if(m[t] > 2)
          {
            isb = false;
            break;
          }
        }
      }
    }

    if(isb)
    {
      is += 1;
    }
    else
    {
      isb = true;
      //cout << "N";
    }
    //cout << " " << is << "\n";
  }

  fout << is;
  return 0;
}