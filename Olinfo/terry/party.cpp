#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int t;
	fin >> t;

	for(int i=0; i<t; i++)
	{
		int N, tot = 0;
		fin >> N;
		int V[N];

		for(int i=0; i<N; i++)
		{
			fin >> V[i];
		}

		sort(V, V+N, greater<int>());

		for(int i : V)
		{
			if(i > 0)
			{
				tot += i;
			}
			else
			{
				break;
			}
		}

		fout << "Case #" << i+1 << ": " << tot << "\n";
	}
	
	return 0;
}