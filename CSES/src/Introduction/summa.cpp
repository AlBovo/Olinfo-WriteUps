#include <string>
#include <iostream>
using namespace std;
 
//ifstream fin("input.txt");
//ofstream fout("output.txt");
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long a, b; cin >> a >> b;
    cout << a + b;
    return 0;
}