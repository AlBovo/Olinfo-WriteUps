// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char input;
    int n;

    fin >> n;;

    vector<char> down = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for(int i=0; i<n; i++)
    {
        fin >> input >> noskipws;

        if(find(down.begin(), down.end(), input) != down.end())
        {
            input = toupper(input);
        }
        else
        {
            input = tolower(input);
        }

        fout << input;
    }

    return 0;
}
