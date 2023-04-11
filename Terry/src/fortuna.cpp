#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k;

    fin >> k;

    for(int i=0; i<k; i++)
    {
        int t, ma = 0;;
        fin >> t;

        int vin[t];
        int per[t];

        for(int e=0; e<t; e++)
        {
            fin >> vin[e];
        }
        for(int e=0; e<t; e++)
        {
            fin >> per[e];
        }
        
        for(int e=0; e<t; e++)
        {
            int temp = 0;
            if(e == 0)
            {
                for(int j=0; j<t; j++)
                {
                    ma += vin[j]*per[j];
                }
            }
            else
            {
                for(int j=0; j<t; j++)
                {
                    temp += vin[j]*per[j];
                }
                
                ma = min(temp, ma);
            }

            int c = per[0], s;
            for(int j=0; j<t; j++)
            {  
                if(j == t-1)
                {
                    per[j] = c;
                    break;
                }
                s = per[j+1];
                per[j] = s;
            }
        }

        fout << "Case #" << i+1 << ": " << ma << endl;
    }

    return 0;
}