#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    pair<int, int> coor = {1,0};
    int pos = 0, salti = 0;
    string num;
    fin >> num;
    for(int i=0; i<num.size(); i++){
        int temp;
        if(num[i] == pos){
            salti++;
        }
        else{
            switch(num[i]){
                case '1': {
                    int x = 0, y = 3;
                    int x1 = coor.first; // 1
                    int y1 = coor.second; // 1
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '2': {
                    int x = 1, y = 3;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '3': {
                    int x = 2, y = 3;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '4': {
                    int x = 0, y = 2;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '5': {
                    int x = 1, y = 2;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '6': {
                    int x = 2, y = 2;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '7': {
                    int x = 0, y = 1;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '8': {
                    int x = 1, y = 1;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '9': {
                    int x = 2, y = 1;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
                case '0': {
                    int x = 1, y = 0;
                    int x1 = coor.first;
                    int y1 = coor.second;
                    salti += abs(x1-x) + abs(y-y1) + 1;
                    coor = {x,y};
                    break;
                }
            }
            pos = num[i];
        }
    }
    fout << salti;
    return 0;
}