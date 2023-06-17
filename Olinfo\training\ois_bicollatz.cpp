// Punti: 50.0
#pragma optimize GCC(O3)
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    ios_base::sync_with_stdio(NULL);
    int n, m, c = 0; fin >> n >> m;
    while(true){
        if(n == 1 && m == 1){
            fout << c;
            return 0;
        }
        else{
            if(n%2 == 0 && m % 2 == 0){
                n /= 2; m /= 2;
            }
            else if(n%2 != 0 && m%2 != 0){
                n = n*3 + 1;
                m = m*3 + 1;
            }
            else{
                if(n%2 !=0){
                    n += 3;
                }
                else{
                    m += 3;
                }
            }
        }
        c++;
    }

    return 0;
}