// Punti: 0.0
#include<bits/stdc++.h>

using namespace std;

int N, K;
pair<int,int> maxi;
vector<pair<int, int>> v;
string t;

/*
int trova(int pos)
{
    for(pair<int, int> p : s)
    {
        
    }
}
*/

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> K >> t;

    for(int i = 0; i<t.size() - K; i++)
    {
        if(int(t[i]) > maxi.first)
        {
            maxi.first = int(t[i]);
            maxi.second = i;
            v.clear();
            v.push_back(maxi);
        }
        else if(int(t[i]) == maxi.first)
        {   
            v.push_back({int(t[i]), i});
        }
    }

    if(v.size() == 1)
    {
        for(int i=v[0].second; i < v[0].second + K; i++)
        {
            cout << t[i];
        }
    }
    /*
    else if(v.size() > 1)
    {
        int st = trova(0);
        for(int i=st; i < st+K; i++)
        {
            cout << t[i];
        }
    }
    */

    return 0;
}