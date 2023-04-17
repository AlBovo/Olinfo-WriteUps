// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

/*
p = 0 Non ancora iniziato
p = 1 Non si è scelto nulla
p = 2 Si è scelto l'array A
p = 3 Si è scelto l'array B
*/

int tempo_massimo(int N, int A[], int B[])
{
    vector<int>A1(N);
    vector<int>B1(N);

    for(int i=0; i<N; i++)
    {
        if(i == 0)
        {
            A1[i] = A[i];
            B1[i] = B[i];
        }
        else if(i == 1)
        {
            A1[i] = max(A1[i-1], B1[i-1]) + A[i];
            B1[i] = B[i];    
        }
        else
        {
            A1[i] = max(A1[i-1], B1[i-1]) + A[i];
            B1[i] = max(A1[i-2], B1[i-2]) + B[i];
        }
    }

    return max(A1[N-1], B1[N-1]);
}
