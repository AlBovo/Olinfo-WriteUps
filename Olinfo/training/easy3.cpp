// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, somma1 = -1, somma2 = -1, temp;
	fin >> n;

	if(n == 1)
	{		
		cout << -1;
		return 0;
	}

	vector<int>Pari;
	vector<int>Dispari;

	for(int i=0; i<n; i++)
	{
		fin >> temp;
		if(temp % 2 == 0)
		{
			Pari.push_back(temp);
		}
		else
		{
			Dispari.push_back(temp);
		}
	}
	if(Pari.size() < 2 && Dispari.size() < 2)
	{			
		cout << -1;
		return 0;
	}

	sort(Pari.begin(), Pari.end(), greater<int>());
	sort(Dispari.begin(), Dispari.end(), greater<int>());

	if(Pari.size() >= 2)
	{
		somma1 = Pari[0] + Pari[1];
	}
	
	if(Dispari.size() >= 2)
	{
		somma2 = Dispari[0] + Dispari[1];
	}

	cout << max(somma1, somma2);
	return 0;
}