// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, n1 = 0, m, h, s;

    fin >> n >> m >> h >> s;

    vector<int> pass;
    vector<pair<int,int>> spaz(50000);
    
    fill(spaz.begin(), spaz.end(), make_pair(INT_MAX, INT_MAX));

    for(int i=0; i<m; i++)
    {
        int temp, temp1, indes;

        fin >> indes;

        fin >> temp;

        fin >> temp1;

        if(temp1 < spaz[indes].first || spaz[indes].first == 0)
        {
            spaz[indes].first = temp1;
            spaz[indes].second = temp;
        }
        if(temp1 < spaz[temp].first || spaz[temp].first == 0)
        {
            spaz[temp].first = temp1;
            spaz[temp].second = indes;
        }
    }

    while(h != s && find(pass.begin(), pass.end(), h) == pass.end())
    {
        pass.push_back(h);
        h = spaz[h].second;

        n1++;
    }

    if(h == s)
    {
        fout << n1;
    }
    else
    {
        fout << -1;
    }

    return 0;
}