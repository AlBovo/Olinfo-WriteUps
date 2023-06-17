// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, pos = 0;
	fin >> n >> m;
	//pair<long long int,int> p;
	for(int i=0; i<m; i++)
	{
		int e, j;
		fin >> e >> j;
		
		if(e == pos)
		{
			pos = j;
		}
		else if(j == pos)
		{
			pos = e;
		}
		
	}
	fout << pos;
	return 0;
}