#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    string ors;
    fin >> ors;
    char finale[ors.size()+1];
    int temp;
    for(int i=0; i<=ors.size(); i++){
        finale[i-1] = ors[ors.size()-i];
    }
    temp = stoi(ors) + stoi(finale);
    fout << temp;
    return 0;
}
