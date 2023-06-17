// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, k;
	fin >> n >> k;
	string D;

	pair<long long int, int> p;
	map<long long int, int> m;

	stringstream s;

	for(int i=0; i<n; i++)
	{
		char temp;
		fin >> temp;
		D += temp;
	}

	for(int i=0; i<=n-k; i++)
	{
		string temp1;
		for(int j=0; j<k; j++)
		{
			temp1 += D[i+j];
		}
		
		//cout << temp1 << " ";

		long long int temp = stoi(temp1);

		//cout << temp << " ";

		if(m.count(temp) == 0)
		{
			m.insert({temp, 1});
		}
		else
		{
			m[temp]++;
		}
	}

	for(pair<long long int,int> i : m)
	{
		if(i.second > p.second)
		{
			p = i;
		}
	}

	s << p.first;
	string ris;
	s >> ris;

	if(ris.size() < k)
	{
		ris = "0" + ris;
	}

	for(int i=0; i<k; i++)
	{
		fout << ris[i] << " ";
	}
	return 0;
}