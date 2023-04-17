// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

long long int V1[151100100]; // 1100100 in binario è uguale a 100 :)

long long int somma_swap(int pos, int N)
{
    long long int totale = 0;

    for(; pos >= 1; pos-=(pos&-pos))
    {
        totale += V1[pos];
    }
    return totale;
}

void aggiorna_swap(int pos, int valore, int N)
{
    for(; pos <= N; pos+=(pos&-pos))
    {
        V1[pos] += valore;
    }
}

long long paletta_sort(int N, int V[])
{
    long long int Totale = 0;
    //V1 = (int*)calloc(N+1, sizeof(int));
    vector<int>SPari;
    vector<int>NPari;

    /*
    SPari.push_back(0);
    NPari.push_back(0);
    */
    
    for(int i=0; i<=N; i++)
    {
        V1[i] = 0;
    }

    for(int i=0; i<N; i++)
    {
        if(V[i] % 2 == 0 && i % 2 == 0)
            SPari.push_back(V[i]);
        else if(V[i] % 2 != 0 && i % 2 != 0)
            NPari.push_back(V[i]);
        else
            return -1;
    }

    /*
    for(int i : SPari)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i : NPari)
    {
        cout << i << " ";
    }
    cout << endl;
    */

    bool fatto;

    //cout << "c" << endl;

    for(int i=SPari.size()-1; i>=0; i--)
    {
        Totale += somma_swap(SPari[i], N);
        aggiorna_swap(SPari[i]+1, 1, N);
    }

    //cout << "b" << endl;

    for(int i=0; i<=N; i++)
    {
        V1[i] = 0;
    }

    //cout << "a" << endl;

    for(int i=NPari.size()-1; i>=0; i--)
    {
        Totale += somma_swap(NPari[i]+1, N+1);
        aggiorna_swap(NPari[i]+1, 1, N+1);
    }

    return Totale;
}
