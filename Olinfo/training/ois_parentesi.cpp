#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int N; fin >> N;
    char sos;
    stack<char> parentesi;
    for(int i=0; i<N; i++){
        fin >> sos;
        if(sos == '{' || sos == '[' || sos == '(' || sos == '<'){
            parentesi.push(sos);
        }
        else{
            if(!parentesi.empty()){
                if(sos == '}' && parentesi.top() == '{'){
                    parentesi.pop();
                }
                else if(sos == ')' && parentesi.top() == '('){
                    parentesi.pop();
                }
                else if(sos == ']' && parentesi.top() == '['){
                    parentesi.pop();
                }
                else if(sos == '>' && parentesi.top() == '<'){
                    parentesi.pop();
                }
                else{
                    fout << "malformata";
                    return 0;
                }
            }
        }
    }
    if(!parentesi.empty()){
        fout << "malformata";
        return 0;
    }
    fout << "corretta";
    return 0;
}
