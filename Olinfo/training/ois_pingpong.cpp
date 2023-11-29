// Punti: 20.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    for(int e=0; e<n; e++){
        int a, b; cin >> a >> b;
        if(a < 33 || b > 52){
            cout << "-1 -1\n";
            continue;
        }
        int temp = a - 33, c = 0;
        vector<pair<int, int>> v;
        while(b > 11 && c < 2){
            pair<int, int> p;
            if(temp >= 10){
                temp -= 10;
                p.first = 10;
            }
            else{
                p.first = temp;
                temp -= temp;
            }
            c++;
            p.second = 11;
            v.push_back(p);
            b -= 11;
        }
        
        for(int i=0; i<3; i++){
            pair<int, int> p;
            if(b >= 10){
                b -= 10;
                p.second = 10;
            }
            else{
                p.second = b;
                b -= b;
            }
            p.first = 11;
            v.push_back(p);
        }
        if(b > 0 || temp > 0){
            cout << "-1 -1\n";
        }
        else{
            for(auto i : v){
                cout << i.first << " " << i.second << "\n";
            }
        }
    }
}