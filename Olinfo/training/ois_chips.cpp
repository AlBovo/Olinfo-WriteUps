// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int T, A, C, r,g,b;

    int resR, resG, resB;

    string res;

    fin>>T;

    for(int i = 0; i<T; i++)
    {
        fin>>A;
        fin>>C;
        fin>>r;
        fin>>g;
        fin>>b;


        resR = A*((r+1)*(r+1) + g*g + b*b) + C * min((r+1),min(g,b));


        resG = A*(r*r + (g+1)*(g+1) + b*b) + C *min(r,min((g+1),b));


        resB = A*(r*r + g*g + (b+1)*(b+1)) + C *min(r,min(g,(b+1)));

        //fout<<resR<<resG<<resB<<endl;

        if(resR>=resG && resR>= resB){
            fout<<"RED"<<endl;
        }
        else{
            if(resG >= resB){
                fout<<"GREEN"<<endl;
            }
            else{
                fout<<"BLUE"<<endl;
            }
        }

    }


    return 0;
}