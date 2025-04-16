// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
bool checcka(int X, int Y){
    return X + Y != 1;
}
int main() {
    int X, Y;
    cin >> X >> Y;
    
    bool w = abs(X - Y) == 1 && ((X + Y) / 2) % 2 == 0;
    cout << (w? "N" : "C") << endl;
    if(w && checcka(X, Y)) {
        cin >> X >> Y;
    }
    while(checcka(X, Y)) {
        int newX = X, newY = Y;
        if(X == 0) {
            newY = 1;
            cout << newX << " " << newY << endl;
            cout.flush();
            return 0;
        }
        if(Y == 0){
            newX = 1;
            cout << newX << " " << newY << endl;
            cout.flush();
            return 0;
        }
        if(X > Y + 1){
            newX = (Y % 2 == 0) ? Y + 1 : Y - 1;
        }
        else if(Y > X + 1) {
            newY = (X % 2 == 0) ? X + 1 : X - 1;
        }
        else if(X == Y + 1) {
            newX -= 2;
        }
        else if(Y == X + 1){
            newY -= 2;
        }
        cout << newX << " " << newY << endl;
        cout.flush();
        if(!checcka(newX, newY)) return 0;
        cin >> X >> Y;
    }
    return 0;
}