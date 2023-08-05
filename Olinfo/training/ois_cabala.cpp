// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

long long int N, M, k = 0, k1;

void trova(long long int ult, long long int num, long long int cifre)
{   
    if(num > k)
        k = num;

    if(cifre < N)
    {
        switch (ult)
        {
            case 3:
                trova(6, (num*10 + 6)%M, cifre+1);
                trova(9, (num*10 + 9)%M, cifre+1);
                break;
            case 6:
                trova(3, (num*10 + 3)%M, cifre+1);
                trova(9, (num*10 + 9)%M, cifre+1);
                break;

            case 9:
                trova(3, (num*10 + 3)%M, cifre+1);
                trova(6, (num*10 + 6)%M, cifre+1);
                break;
            case 0:
                trova(3, (num*10 + 3)%M, cifre+1);
                trova(6, (num*10 + 6)%M, cifre+1);
                trova(9, (num*10 + 9)%M, cifre+1);
                break;
        }
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int T; fin >> T;

    for(int i=0; i<T; i++)
    {
        fin >> N >> M;

        trova(0,0,0);
        
        fout << k << " ";
        k = 0;
        k1 = 0;       
    }

    return 0;
}