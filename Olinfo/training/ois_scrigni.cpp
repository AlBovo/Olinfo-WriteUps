#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main(){    
    long long n; fin>>n;
    double res = (double)(n * (n-1)) / 4;
    fout << res;
    return 0;
}
