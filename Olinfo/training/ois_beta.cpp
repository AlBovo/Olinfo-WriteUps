// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	int N, devnum = -1, bin;
	fin >> N;
	bool devtrigger = false;
	vector <int> memo;
	
    for(int i = 0; i < N; i++)
    {
        fin >> bin;
        memo.push_back(bin);
    }
    
    sort(memo.begin(), memo.end());
    
    for(int i = 0; i < N-1; i++)
    {
        if(memo[i]==memo[i+1])
        {
            if(devtrigger)
            {
                fout << "YES";
                return 0;
            }
            else
            {
                devtrigger = true;
                
                while(memo[i]==memo[i+1] && i < N-1)
                {
                    i++;
                }
            }
        }
    }
    
	fout << "NO";
	return 0;
}