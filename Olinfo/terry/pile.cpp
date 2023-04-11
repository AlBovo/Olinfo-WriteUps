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

		for(int e=0; e<N; e++)
		{
			int n1, n2, n3;
			fin >> n1 >> n2 >> n3;
			tot += max(n1, max(n2, n3));
		}

		fout << "Case #" << i+1 << ": " << tot << "\n";
	}
	
	return 0;
}