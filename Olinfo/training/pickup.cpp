// Punti: 0.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int a, b;
	
	bool prov = true;
	
	long long int k, temp, i = 1, r = 0;
	
	vector<long long int> Val;
	
	fin >> a >> b >> k;
	
	while(true)
	{
		long long int sum = 0, t, n, m;
		stringstream sos;
		string t1;
		prov = true;
		
		t = i * a;
		
		sos << t;
		
		t1 = sos.str();
		
		while(n>0)
		{
			m = n % 10;
			sum += sum + m;
			n /= 10;
		}
		
		for(int i=0; i<t1.size(); i++)
		{
		    if(t1[i] == 0)
		    {
		        prov = false;
		    }
		}
		
		if(sum % b == 0 && prov)
		{
			r++;
		}
		
		if(r == k)
		{
			fout << t;
			return 0;
		}
		
		i++;
	}
	
	return 0;
} 