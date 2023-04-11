#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N; fin >> N;
	for(int i=0; i<N; i++){
		map<string, int> m;
		int n1, n2, n3, n4; fin >> n1 >> n2 >> n3 >> n4;
		int k; fin >> k;
		string s1, s2, s3, s4; fin >> s1 >> s2 >> s3 >> s4;

		for(int x = 0; x<s1.size()-k+1; x++){
			unordered_map<string, bool> m1;
			if(!m.count(s1.substr(x, k)) && !m1.count(s1.substr(x,k))) {
				m[s1.substr(x, k)] = 1;
				m1[s1.substr(x, k)] = 1;		
			}
			else if(!m1.count(s1.substr(x,k))){
				m[s1.substr(x, k)]++;
				m1[s1.substr(x, k)] = 1;	
			}
		}
		for(int x = 0; x<s2.size()-k+1; x++){
			unordered_map<string, bool> m1;
			if(!m.count(s2.substr(x, k)) && !m1.count(s2.substr(x,k))) {
				m[s2.substr(x, k)] = 1;
				m1[s2.substr(x, k)] = 1;		
			}
			else if(!m1.count(s2.substr(x,k))){
				m[s2.substr(x, k)]++;
				m1[s2.substr(x, k)] = 1;	
			}
		}
		for(int x = 0; x<s3.size()-k+1; x++){
			unordered_map<string, bool> m1;
			if(!m.count(s3.substr(x, k)) && !m1.count(s3.substr(x,k))) {
				m[s3.substr(x, k)] = 1;
				m1[s3.substr(x, k)] = 1;		
			}
			else if(!m1.count(s3.substr(x,k))){
				m[s3.substr(x, k)]++;
				m1[s3.substr(x, k)] = 1;	
			}
		}
		for(int x = 0; x<s4.size()-k+1; x++){
			unordered_map<string, bool> m1;
			if(!m.count(s4.substr(x, k)) && !m1.count(s4.substr(x,k))) {
				m[s4.substr(x, k)] = 1;
				m1[s4.substr(x, k)] = 1;		
			}
			else if(!m1.count(s4.substr(x,k))){
				m[s4.substr(x, k)]++;
				m1[s4.substr(x, k)] = 1;	
			}
		}
		string m1; int maxi = 0;
		for(auto e : m){
			if(e.second > maxi){
				maxi = e.second;
				m1 = e.first;
			}
		}
		cout << m1 << " ";
		fout << "Case #" << i+1 << ": ";

		for(int x = 0; x<s1.size()-k+1; x++){
			if(s1.substr(x, k) == m1) {fout << x << " "; break;}
		}
		for(int x = 0; x<s2.size()-k+1; x++){
			if(s2.substr(x, k) == m1) {fout << x << " "; break;}
		}
		for(int x = 0; x<s3.size()-k+1; x++){
			if(s3.substr(x, k) == m1) {fout << x << " "; break;}
		}
		for(int x = 0; x<s4.size()-k+1; x++){
			if(s4.substr(x, k) == m1) {fout << x << " "; break;}
		}
		fout << "\n";
	}
}