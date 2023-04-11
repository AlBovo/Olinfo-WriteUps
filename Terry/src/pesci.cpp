#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int n; fin >> n;
    cout << n << "\n";
    for(int i=0; i<n; i++){
        int k, s, c = 0; fin >> k >> s;
        while(k > 0){
            c += k;
            k /= s;
            cout << c << " ";
        }
        cout << endl;
        fout << "Case #" << i+1 << ": " << c << "\n";
    }
    return 0;
}