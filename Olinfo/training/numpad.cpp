// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    pair<int, int> coor;
    int pos = 0;

    coor = make_pair(1,0);

    int salti = 0;
    string num;

    fin >> num;

    for(int i=0; i<num.size(); i++)
    {
        int temp;

        if(num[i] == pos)
        {
            salti++;
        }
        else
        {
            switch(num[i])
            {
                case '1':
                {
                    int x = 0, y = 3;
                    int x1 = coor.first; // 1
                    int y1 = coor.second; // 1

                    salti += abs(x1-x) + abs(y-y1) + 1;

                    //cout << "1: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '2':
                {
                    int x = 1, y = 3;
                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;
                    
                    //cout << "2: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '3':
                {
                    int x = 2, y = 3;

                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;
                    
                    //cout << "3: " << abs(x1-x) + abs(y-y1) + 1 << "\n";
                    
                    coor = make_pair(x,y);
                    break;
                }
                case '4':
                {
                    int x = 0, y = 2;
                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;
                    
                    //cout << "4: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '5':
                {
                    int x = 1, y = 2;
                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;

                    //cout << "5: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '6':
                {
                    int x = 2, y = 2;
                    int x1 = coor.first;
                    int y1 = coor.second;


                    salti += abs(x1-x) + abs(y-y1) + 1;

                    //cout << "6: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '7':
                {
                    int x = 0, y = 1;
                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;

                    //cout << "7: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '8':
                {
                    int x = 1, y = 1; // 
                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;
                    
                    //cout << "8: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '9':
                {
                    int x = 2, y = 1;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    
                    //cout << "9: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
                case '0':
                {
                    int x = 1, y = 0;
                    int x1 = coor.first;
                    int y1 = coor.second;

                    salti += abs(x1-x) + abs(y-y1) + 1;
                    
                    //cout << "0: " << abs(x1-x) + abs(y-y1) + 1 << "\n";

                    coor = make_pair(x,y);
                    break;
                }
            }
            pos = num[i];
        }
        
        //cout << "salti: " << salti << "\n";
    }
    
    fout << salti;

    return 0;
}