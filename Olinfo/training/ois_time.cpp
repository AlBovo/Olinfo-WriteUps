#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main() {
    int H0, H1, N0, N1; fin >> H0 >> N0 >> H1 >> N1;
    N0 = H0 * 60 + N0;
    N1 = H1 * 60 + N1;
    int oramin = 0, ora = 0;
    if(N0 > N1){
        oramin = 1440 - N0 + N1;
    }
    else{
        oramin = N1 - N0;
    }
    fout << oramin / 60 << " " << oramin % 60;
    return 0;
}
