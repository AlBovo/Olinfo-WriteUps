// Punti: 20.15
#include <bits/stdc++.h>
#pragma optimize GCC("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
bool test(string qry);

string analizza(int N){
    string t = "";
    bool a = test("0");
    if(!a){
        for(int i=0; i<N; i++){
            t += "1";
        }
        return t;
    }
    else if(!test("1")){
        for(int i=0; i<N; i++){
            t += "0";
        }
        return t;
    }
    bool fondo = false;
    while(t.size() < N){
        if(!fondo){
            bool s = test(t + "0");
            if(!s){
                bool s1 = test(t + "1");
                if(!s1)
                    fondo = true;
                else{
                    if(s1){
                        t += "1";
                    }
                }  
            }
            else{
                t += "0";
            }
        }
        else{
            bool s = test("0" + t);
            if(!s){
                bool s1 = test("1" + t);
                if(!s1)
                    break;
                else{
                    t = "1" + t;
                }
            }
            else{
                t = "0" + t;
            }
        }
    }
    return t;
}