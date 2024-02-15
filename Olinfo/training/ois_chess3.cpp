// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int T; fin >> T;
    for(int t = 0; t < T; t++){
        char g[8][8]; int x,y;
        bool ok = true;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                fin >> g[i][j];
                if(g[i][j] == 'q'){
                    x = i; y = j;
                }
            }
        }
        //rook & queen
        int x1 = x, y1 = y;
        while(x1 > 0){
            x1--;
            if(g[x1][y1] == 'R' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}
        x1 = x, y1 = y;
        while(x1 < 7){
            x1++;
            if(g[x1][y1] == 'R' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}
        x1 = x, y1 = y;
        while(y1 < 7){
            y1++;
            if(g[x1][y1] == 'R' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}
        x1 = x, y1 = y;
        while(y1 > 0){
            y1--;
            if(g[x1][y1] == 'R' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}

        //bishop & queen
        x1 = x, y1 = y;
        while(x1 > 0 && y1 > 0){
            x1--; y1--;
            if(g[x1][y1] == 'B' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}
        x1 = x, y1 = y;
        while(x1 > 0 && y1 < 7){
            x1--; y1++;
            if(g[x1][y1] == 'B' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}
        x1 = x, y1 = y;
        while(x1 < 7 && y1 < 7){
            x1++; y1++;
            if(g[x1][y1] == 'B' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}
        x1 = x, y1 = y;
        while(x1 < 7 && y1 > 0){
            x1++; y1--;
            if(g[x1][y1] == 'B' || g[x1][y1] == 'Q'){ok=false; break;}
            else if(g[x1][y1] == '.'){continue;}
            else break;
        }
        if(!ok){cout << "YES" << endl; continue;}

        //knight
        if(x < 6 && y < 7 && g[x+2][y+1] == 'N'){cout << "YES" << endl; continue;}
        if(x > 1 && y < 7 && g[x-2][y+1] == 'N'){cout << "YES" << endl; continue;}
        if(x < 6 && y > 0 && g[x+2][y-1] == 'N'){cout << "YES" << endl; continue;}
        if(x > 1 && y > 0 && g[x-2][y-1] == 'N'){cout << "YES" << endl; continue;}
        if(y < 6 && x < 7 && g[x+1][y+2] == 'N'){cout << "YES" << endl; continue;}
        if(y < 6 && x > 0 && g[x-1][y+2] == 'N'){cout << "YES" << endl; continue;}
        if(y > 1 && x < 7 && g[x+1][y-2] == 'N'){cout << "YES" << endl; continue;}
        if(y > 1 && x > 0 && g[x-1][y-2] == 'N'){cout << "YES" << endl; continue;}
        //pawn
        if(y < 7 && x < 7 && g[x+1][y+1] == 'P'){cout << "YES" << endl; continue;}
        if(y > 0 && x < 7 && g[x+1][y-1] == 'P'){cout << "YES" << endl; continue;}

        cout << "NO" << endl;
    }

    return 0;
}
