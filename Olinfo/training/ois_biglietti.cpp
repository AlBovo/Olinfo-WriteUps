#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long viaggi, costo1, ncarnet, costo2, tot = 0;
    fin >> viaggi >> ncarnet >> costo1 >> costo2;
    if(ncarnet*costo1 > costo2){
        fout << (viaggi / ncarnet)* costo2 + min((viaggi % ncarnet) * costo1, costo2);
    }
    else{
        fout << viaggi*costo1;
    }
    return 0;
}