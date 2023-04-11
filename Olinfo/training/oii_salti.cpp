#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main(){
    int distanza, potenza, numeroSalti = 0; fin >> distanza;
    while(distanza > 0){
        potenza = 0;
        while(pow(2, potenza) <= distanza){
            potenza++;
        }
        distanza = distanza - pow(2, potenza - 1);
        numeroSalti++;
    }
    fout << numeroSalti;
    return 0;
}