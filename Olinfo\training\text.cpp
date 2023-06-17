// Punti: 100.0
#include <iostream>
#pragma GCC optimize("O2")
int main()
{
    std::ios_base::sync_with_stdio(0);
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    std::cin.tie(0); std::cout.tie(0);
    int n, k, k1 = 0;
    std::cin >> n >> k;
    k1 = k;
    std::string i;
    for(int e=0; e<n; e++)
    {
        std::cin >> i;
        if(k1>=i.length() && k1 > 0)
        {
            std::cout << i << " ";
            k1 -= i.length() + 1;
        }
        else
        {
            k1 = k;
            std::cout << "\n" << i << " ";
            k1 -= i.length() +1;
        }
    }
    return 0;
}