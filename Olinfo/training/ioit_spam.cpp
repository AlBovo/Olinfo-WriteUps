// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, n1, gd = 0, bd = 0, k;

    fin >> n;

    string temp;

    vector<string> bad;
    vector<string> good;

    for(int i=0; i<n; i++)
    {
        fin >> temp;
        bad.push_back(temp);
    }

    fin >> n1;

    for(int i=0; i<n1; i++)
    {
        fin >> temp;
        good.push_back(temp);
    }

    fin >> k;

    for(int i=0; i<k; i++)
    {
        int tem;
        unordered_set<string> word;
        string tems;
        fin >> tem;

        for(int e=0; e<tem; e++)
        {
            fin >> tems;
            word.insert(tems);
        }

        int ko = 0, ko1 = 0;

        for(int e=0; e<n; e++)
        {
            if(find(word.begin(), word.end(), bad[e]) != word.end() && ko == 0)
            {
                ko--;
                break;
            }
        }
        for(int e=0; e<n1; e++)
        {
            if(find(word.begin(), word.end(), good[e]) != word.end() && ko1 == 0)
            {
                ko1++;
                break;
            }
        }

        if(ko1  == 0 && ko == -1)
        {
            bd++;
        }
        else if(ko1 == 1 && ko == 0)
        {
            gd++;
        }
    }

    fout << bd << " " << gd;

    return 0;
}