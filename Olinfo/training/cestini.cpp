// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Cest;

vector<int>Bin;

int inizia(int N, int M)
{
	for(int i = 0; i < N; i++)
	{
		Bin.push_back(i);
	}
    
    Cest.push_back(Bin);
    
    for(int i = 1; i < M; i++)
    {
        Cest.push_back(vector<int>());
    }
    
	return 0;
}

void sposta(int a, int b)
{
	Cest[b].push_back(Cest[a].back());
    Cest[a].pop_back();
}

int controlla(int a, int i)
{
	if(i < Cest[a].size())
	{
        return Cest[a][i];
	}
	else
	{
		return -1;
	}
}
