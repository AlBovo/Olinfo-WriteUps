#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k, ma, mi;

    fin >> k;

    for(int i=0; i<k; i++)
    {
        for(int e=0; e<3; e++)
        {
            int a, b;
            fin >> a >> b;

            if(e == 0)
            {
                ma = a;
                mi = b;
            }
            else
            {
                ma = max(ma, a);
                mi = min(mi, b);
            }
        }

        fout << "Case #" << i+1 << ": " << mi-ma << endl;
    }

    return 0;
}