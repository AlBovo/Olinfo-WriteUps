// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int N, k; fin >> N;
    int vittorie[N];
    fill(vittorie, vittorie+N, 0);
    k = (N*(N-1))/2;

    for(int i=0; i<k; i++)
    {
        int s1, s2, g1, g2; fin >> s1 >> s2 >> g1 >> g2;
        //cout << s1 << " " << s2 << " " << g1 << " " << g2 << "\n";

        if(g1 > g2)
        {
            vittorie[s1-1] += 3;
            //cout << "s" << s1-1 << " " << vittorie[s1-1] << "\n";
        } 
        else if(g2 > g1)
        {
            vittorie[s2-1] += 3;
            //cout << "p" << s2-1 << " " << vittorie[s2-1] << "\n";
        } 
        else if(g2 == g1)
        {   
            vittorie[s1-1]++;
            vittorie[s2-1]++;
            //cout << "r" << min(s1, s2)-1 << " " << vittorie[min(s1, s2)-1] << "\n";
        } 
    }

    int pos = -1, maxi = -1; 

    for(int i=0; i<N; i++)
    {
        if(vittorie[i] > maxi) pos = i; maxi = max(maxi, vittorie[i]);
    }
    fout << pos+1 << " " << maxi;
    return 0;
}