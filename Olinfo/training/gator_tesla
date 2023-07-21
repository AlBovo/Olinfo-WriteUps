// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    long long n; fin>>n;
    vector<long long>v(n);
    for(long long &i:v){
        fin >> i;
    }

    for(long long i=0; i<n; i++){
        long long c = v[i];
        bool s = true;
        for(long long e=1; e<n; e++){
            if(c-10 < 0){
                s = false;
                break;
            }
            else{
                c +=v[int((e+i)%n)]-10;
            }
        }
        if(s){
            fout << i+1;
            break;
        }
    }
    return 0;
}