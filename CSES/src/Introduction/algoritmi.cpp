#include <string>
#include <iostream>
#include <fstream>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long s; cin >> s;
    while(s != 1){
        cout << s << " ";
        if(s % 2 == 0){
            s /= 2;
        }
        else{
            s = s*3+1;
        }
    }
    cout << "1";
    return 0;
}