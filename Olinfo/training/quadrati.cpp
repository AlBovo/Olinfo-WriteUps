// Punti: 100.0
#include<iostream>
#include<fstream>
#include<cmath>
 
using namespace std;
 
int main()
{
    ifstream fin ( "input.txt");
    ofstream fout("output.txt");
 
    long long a, b;
    fin >> a >> b;
	
    long long aa= ceil(sqrt(a));
    long long bb=floor(sqrt(b));
 
    fout << bb-aa+1;
    return 0;
}