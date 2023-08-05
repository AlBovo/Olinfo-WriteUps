// Punti: 2.0
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fastread(FILE *f)
{
    ll k = 0;
    char c = fgetc(f);
    bool neg = false;
    
    if(c == '-')
    {
        neg = true;
        c = fgetc(f);
    }
    
    while(true)
    {
        if(c >= '0' && c <= '9')
        {
            k = k * 10 + (c - '0');
        }
        else
        {
            break;
        }
        c = fgetc(f);
    }
    
    if(neg)
    {
        k *= -1;
    }
    
    return k;
}

long long somma(FILE *f)
{
    ll N = fastread(f), k = 0;

    for(ll i=0; i<N; i++) k += fastread(f);

    return k;
}