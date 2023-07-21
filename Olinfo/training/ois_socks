// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N, C, trovati = 0;
	long long int swap = 0; 
	fin >> N >> C;

	map<int, long long int> Map;

	/*for(int i=0; i<=C; i++)
		Map.insert({i, -1});
	*/

	for(int i=0; i<N; i++)
	{
		long long int x; 
		fin >> x;

		if(Map.count(x) == 0)
		{
			Map[x] = trovati;
			swap += trovati;
			trovati++;
		}
		else
		{
			swap += Map.at(x);
		}	
	}
	fout << swap;
	return 0;
}