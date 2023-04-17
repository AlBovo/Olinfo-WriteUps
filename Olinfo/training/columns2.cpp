// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N, K;
	long long int rest = 0, pal = 0;
	fin >> N >> K;
	vector<int>L(N);

	for(int i=0; i<N; i++)
	{
		fin >> L[i];
	}

	sort(L.begin(), L.end(), less<int>());

	for(int i : L)
	{
		int volte = 0;
		while(i >= K && volte < 10)
		{
			i -= K;
			volte++;
			pal++;
		}
		if(i == K)
		{
			i = 0;
			pal++;
		}
		rest += i;
		//cout << rest << '\n';
	}

	cout << pal << " " << rest;

	return 0;
}