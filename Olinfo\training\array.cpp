// Punti: 100.0
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int N, temp;
	double somma = 0;
	
	fin >> N;
	for(int i = 0; i < N; i++)
	{
		fin >> temp;
		
		somma += temp;
	}
	
	fout << somma << " " << somma/N;
	
	return 0;
}