// Punti: 0.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    unsigned long long k, x; fin >> k >> x;
    unsigned long long tot = 0, boh = x / 2;
    long long s = (int)(pow(10,boh))%666013;
    for(long long i=0; i<k; i++){
        unsigned long long f = (s + ((i * (unsigned long long)pow(10, boh-1))%666013))%666013, t = (f* (unsigned long long)pow(10, boh-1))%666013,c = boh;
        while(f>0 && c >= 0){
        	t += (unsigned long long)((f % 10) * pow(10, c))%666013;
        	f = (unsigned long long)(f/10);
        	c--;
        }
        tot = (tot+t)%666013;
    }
    fout << tot%666013;
    return 0;
}