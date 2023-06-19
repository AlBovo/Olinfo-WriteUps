// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	long N;
	
	fin >> N;
	
	long Val[N];
	
	for(long i = 0; i < N; i++)
	{
		fin >> Val[i];
	}
	
	for(int i=1; i<7; i++)
	{
		long pos = 0, tiri = 0;
		
		pos += Val[pos];
		
		while(pos < N)
		{
			tiri++;
			pos += i;
			
			if(Val[pos] > 0)
			{
			    while(Val[pos] != 0 && pos < N)
			    {
			        pos += Val[pos];
			    }
			}
		}
		
		fout << tiri << " ";
	}
	
	return 0;
} 
