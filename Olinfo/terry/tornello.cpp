#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int trova(){
    int n; fin >> n;
    int dentro = 0, fuori = 0, totale = 0;
    for(int i=0; i<n; i++){
        string s; fin >> s;
        if(s == "-1"){
            if(dentro > 0){
                dentro--;
                fuori++;
            }
            else{
                totale++;
                fuori++;
            }
        }
        else if(s == "+1"){
            if(fuori > 0){
                fuori--;
                dentro++;
            }
            else{
                totale++;
                dentro++;
            }
        }
    }
    return totale;
}

int main(){
    int n; fin >> n;
    for(int i=0; i<n; i++){
        fout << "Case #" << i+1 << ": " << trova() << "\n";
    }
}