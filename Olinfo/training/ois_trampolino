// Punti: 70.0
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
long long n;
vector<long long>tr(100001);
vector<long long>tem(100001, -1);
long long salto(long long pos){
  if(tem[pos] >= 0){
    return tem[pos];
  }
  long long mini = (long long)10e9, r = tr[pos];
  while(r > 0){
    if(n <= pos+r){
      mini = 1;
      break;
    }
    else{
      mini = min(salto(pos+r)+1, mini);
    }
    r--;
  }
  tem[pos] = mini;
  return mini;
}

int main(){
  ios_base::sync_with_stdio(false);
  fin.tie(0); fout.tie(0);
  fin >> n;
  for(long long i=0; i<n; i++){
    fin >> tr[i];
  }
  fout << salto(0);
  return 0;
}