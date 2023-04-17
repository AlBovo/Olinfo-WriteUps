// Punti: 100.0
#include<bits/stdc++.h>

using namespace std;

int p1, p2, terre = 0;
int Carta[1001][1001];
bool temp = true;

void replace(pair<int, int> PosB)
{
    Carta[PosB.first][PosB.second] = 0;
}

bool controlla(pair<int, int> PosK)
{
    int p11 = PosK.first, p22 = PosK.second;

    if(p11 == 0 || p11 == p1-1 || p22 == 0 || p22 == p2-1)
    {
        return false;
    }
    return true;
}

void trova(pair<int, int> PosZ)
{
    int p11 = PosZ.first, p22 = PosZ.second;
    pair<int, int> Temp;

    bool b1, b2, b3, b4;

    if(p11 != p1-1)
    {
        if(Carta[p11 + 1][p22] == 1)
        {
            Temp.first = p11 + 1;
            Temp.second = p22;
            if(controlla(Temp))
            {
                replace(Temp);
                trova(Temp);
            }
            else
            {
                temp = false;
                //return;
            }
        }
    }
    if(p22 != p2-1)
    {
        if(Carta[p11][p22 + 1] == 1)
        {
            Temp.first = p11;
            Temp.second = p22 + 1;
            if(controlla(Temp))
            {
                replace(Temp);
                trova(Temp);
            }
            else
            {
                temp = false;
                //return;
            }
        }
    }
    if(p11 != 0)
    {
        if(Carta[p11 - 1][p22] == 1)
        {
            Temp.first = p11 - 1;
            Temp.second = p22;
            if(controlla(Temp))
            {
                replace(Temp);
                trova(Temp);
            }
            else
            {
                temp = false;
                //return;
            }
        }
    }
    if(p22 != 0)
    {
        if(Carta[p11][p22 - 1] == 1)
        {
            Temp.first = p11;
            Temp.second = p22 - 1;
            if(controlla(Temp))
            {
                replace(Temp);
                trova(Temp);
            }
            else
            {
                temp = false;
                //return;
            }
        }
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<pair<int,int>> Pos;

    fin >> p1 >> p2;

    for(int i=0; i<p1; i++)
    {
        for(int e=0; e<p2; e++)
        {
            fin >> Carta[i][e];
            if(Carta[i][e] == 1 && controlla({i, e}))
            {
                Pos.push_back({i, e});
            }
        }
    }

    /*
    for(int i=0; i<p1; i++)
    {
        for(int e=0; e<p2; e++)
        {
            cout << Carta[i][e] << " ";
        }
        cout << endl;
    }
    */

    for(int i=0; i<Pos.size(); i++)
    {
        pair<int,int> s = Pos[i];
        if(Carta[s.first][s.second] == 1)
        {
            terre += 1;
            trova(s);
        }
        if(temp == false)
        {
            terre -= 1;
            temp = true;
        }
        //cout << terre << endl;
    }

    cout << terre;

    return 0;
}