// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
	string s, t = ""; fin >> s;
	long long d = 0, c = 0, temp = 1;
	for(int i=0; i<=(int)s.size(); i++){
		if(i == (int)s.size() || s[i] == 'x'){
			temp = stoll(t);
			// cerr << t << "\n";
			while(temp % 2 == 0){
				// cerr << t << " 2\n";
				++d;
				temp /= 2;
			}
			while(temp % 5 == 0){
				// cerr << t << " 5\n";
				++c;
				temp /= 5;
			}
			t = "";
		} else {
			t += s[i];
		}
	}
	fout << min(d, c);
	return 0;
}
