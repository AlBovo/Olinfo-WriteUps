// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n; fin >> n;
    stack<int>last;
    for(int i=0; i<n; i++){
        int t; fin >> t;
        if(!i || last.top() >= t){
            last.push(t);
        }
        else if(last.top() < t){
            while(!last.empty() && last.top() < t){
                last.pop();
            }
            last.push(t);
        }
    }
    fout << last.size();
    return 0;
}