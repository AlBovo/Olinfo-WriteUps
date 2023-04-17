// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    queue<string> q;
    map<string, bool>m;
    int N; fin >> N;
    string k[N];

    for(int i=0; i<N; i++)
    {
        fin >> k[i];
    }

    for(int i=N-1; i >= 0; i--)
    {
        string temp = k[i];

        if(!m.count(temp))
        {
            m[temp] = true;
            q.push(temp);
        }
    }

    //cout << q.size();

    while(!q.empty())
    {
        cout << q.front() << "\n";
        q.pop();
    }

    return 0;
}
