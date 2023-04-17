// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int trova_massimo(int N, vector<int> V)
{
    sort(V.begin(), V.end(), greater<int>());

	return V[0];
}