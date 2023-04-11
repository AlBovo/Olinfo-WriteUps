#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    long long n; fin >> n;
    for(long long i=0; i<n; i++){
        long long k, m, c; fin >> k >> m >> c;
        fout << "Case #" << i+1 << ": " << k / m << " ";
        k -= m * (k / m);
        fout << k /c << "\n";
    }
    return 0;
}