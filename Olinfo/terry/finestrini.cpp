#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<long long> A;
vector<long long> B;
map<tuple<long long, long long, long long>, long long> m;
long long f;

long long trova(long long pos, pair<long long, long long>k)
{
	if(pos == f){
		return 0;
	}

	if(k.second == 1){
		if(!k.first){ // 0
			if(!m.count({pos+1, 1, 0})){
				m[{pos+1, 1, 0}] = trova(pos+1, {1, 0});
			}
			return m[{pos+1, 1, 0}] + A[pos];
		}
		else{ // 1
			if(!m.count({pos+1, 0, 0})){
				m[{pos+1, 0, 0}] = trova(pos+1, {0, 0});
			}
			return m[{pos+1, 0, 0}] + B[pos];
		}
	}
	else{ // 0
		if(!k.first){ // 0
			if(!m.count({pos+1, 0, k.second+1}) && !m.count({pos+1, 1, 0})){
				m[{pos+1, 0, k.second+1}] = trova(pos+1, {0, k.second+1});
				m[{pos+1, 1, 0}] = trova(pos+1, {1, 0});
			}
			else if(!m.count({pos+1, 0, k.second+1}) && m.count({pos+1, 1, 0})){
				m[{pos+1, 0, k.second+1}] = trova(pos+1, {0, k.second+1});
			}
			else if(m.count({pos+1, 0, k.second+1}) && !m.count({pos+1, 1, 0})){
				m[{pos+1, 1, 0}] = trova(pos+1, {1, 0});
			}
			return min(m[{pos+1, 0, k.second+1}], m[{pos+1, 1, 0}]) + A[pos];
		}
		else{ // 1
			if(!m.count({pos+1, 0, 0}) && !m.count({pos+1, 1, k.second+1})){
				m[{pos+1, 0, 0}] = trova(pos+1, {0, 0});
				m[{pos+1, 1, k.second+1}] = trova(pos+1, {1, k.second+1});
			}
			else if(!m.count({pos+1, 0, 0}) && m.count({pos+1, 1, k.second+1})){
				m[{pos+1, 0, 0}] = trova(pos+1, {0, 0});
			}
			else if(m.count({pos+1, 0, 0}) && !m.count({pos+1, 1, k.second+1})){
				m[{pos+1, 1, k.second+1}] = trova(pos+1, {1, k.second+1});
			}
			return min(m[{pos+1, 0, 0}], m[{pos+1, 1, k.second+1}])+B[pos];
		}
	}
}

int main(){
    long long n; fin >> n;
	for(long long i=0; i<n; i++){
        fin >> f;
		for(long long e=0; e<f; e++){
			long long t, t1; fin >> t >> t1;
			A.push_back(t);
			B.push_back(t1);
		}
		fout << "Case #" << i+1 << ": " << min(trova(0, {0,0}), trova(0, {1,0})) << "\n";
		A.clear();
		B.clear();
		m.clear();
	}
	return 0;
}