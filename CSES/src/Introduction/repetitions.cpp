#include<bits/stdc++.h>
using namespace std;

/*
ifstream fin("input.txt");
ofstream fout("output.txt");
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int last = 0, maxi = 0; char l = ' ';
	for(int i=0; i<(int)s.size(); i++){
		if(s[i] != l){
			l = s[i];
			maxi = max(maxi, i - last);
			last = i;
		}
	}
	maxi = max(maxi, (int)s.size()-last);
	cout << maxi;
	return 0;	
}
