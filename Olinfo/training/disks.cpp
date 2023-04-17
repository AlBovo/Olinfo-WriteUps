// Punti: 0.0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int inizio, fine, k;
	long long int tempo, durata = 0;
	
	fin >> inizio >> fine >> tempo;
	
	k = (24 - fine) + inizio;
	
	while(tempo > 0)
	{
		if(tempo >= k)
		{
			durata += k;
			tempo -= k;
		}
		else
		{
			fout << durata;
			return 0;
		}
		
		if(tempo >= fine - inizio)
		{
			tempo -= fine - inizio;
		}
		else
		{
			fout << durata;
			return 0;
		}
	}
	
	return 0;
}