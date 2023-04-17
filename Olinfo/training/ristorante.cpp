// Punti: 0.0
#include<bits/stdc++.h>
using namespace std;
int conta(int N, vector<int> &A, vector<int> &P, vector<int> &D)
{
	vector<int>m;
	int tot = 0;
	
	for(int i : A)
	{
	    if(find(m.begin(), m.end(), i) == m.end())
	    {
	    	m.push_back(i);
	    	tot++;
	    }
	}
	
	for(int i : P)
	{
		if(find(m.begin(), m.end(), i) == m.end())
	    {
	    	m.push_back(i);
	    	tot++;
	    }
	}
	
	for(int i : D)
	{
	    if(find(m.begin(), m.end(), i) == m.end())
	    {
	    	m.push_back(i);
	    	tot++;
	    }
	}
	
	return tot;
}