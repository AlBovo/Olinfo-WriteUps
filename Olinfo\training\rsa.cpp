// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

long long fast_exp(int b, int e, int m){
    if(e == 0){
        return 1;
    }
    if(e == 1){
        return b;
    }
    long long f = fast_exp(b, e/2, m);
    if(e % 2 == 0){
        return (f%m * f%m)%m;
    }
    return (f%m * f%m * b%m)%m;
}

void decifra(int N, int d, int L, int messaggio[], char plaintext[])
{
    for(int i = 0; i < L; i++){
        plaintext[i] = fast_exp(messaggio[i], d, N);
    }
}